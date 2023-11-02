#import "aiUtils.h"
#import "aiMiddleware.h"


@implementation PHGBlockMiddleware

- (instancetype)initWithBlock:(PHGMiddlewareBlock)block
{
    if (self = [super init]) {
        _block = block;
    }
    return self;
}

- (void)context:(aiContext *)context next:(PHGMiddlewareNext)next
{
    self.block(context, next);
}

@end


@implementation PHGMiddlewareRunner

- (instancetype)initWithMiddlewares:(NSArray<id<aiMiddleware>> *_Nonnull)middlewares
{
    if (self = [super init]) {
        _middlewares = middlewares;
    }
    return self;
}

- (void)run:(aiContext *_Nonnull)context callback:(RunMiddlewaresCallback _Nullable)callback
{
    [self runMiddlewares:self.middlewares context:context callback:callback];
}

// TODO: Maybe rename aiContext to PHGEvent to be a bit more clear?
// We could also use some sanity check / other types of logging here.
- (void)runMiddlewares:(NSArray<id<aiMiddleware>> *_Nonnull)middlewares
               context:(aiContext *_Nonnull)context
              callback:(RunMiddlewaresCallback _Nullable)callback
{
    BOOL earlyExit = context == nil;
    if (middlewares.count == 0 || earlyExit) {
        if (callback) {
            callback(earlyExit, middlewares);
        }
        return;
    }

    [middlewares[0] context:context next:^(aiContext *_Nullable newContext) {
        NSArray *remainingMiddlewares = [middlewares subarrayWithRange:NSMakeRange(1, middlewares.count - 1)];
        [self runMiddlewares:remainingMiddlewares context:newContext callback:callback];
    }];
}

@end
