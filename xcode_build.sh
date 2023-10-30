echo "Removing previous build"
rm -r build
rm -r aiAnalytics.xcframework
rm -r aiAnalytics_Pods.xcframework

echo "Building for iOS..."
xcodebuild archive \
    -workspace aiAnalytics.xcworkspace \
    -sdk iphoneos IPHONEOS_DEPLOYMENT_TARGET=13.0 \
    -arch armv7 -arch arm64 \
    BUILD_LIBRARY_FOR_DISTRIBUTION=YES \
    -scheme "aiAnalytics" \
    -archivePath "./build/iphoneos/aiAnalytics.xcarchive" SKIP_INSTALL=NO

echo "Building for iOS Simulator..."
xcodebuild archive \
    -workspace aiAnalytics.xcworkspace \
    -sdk iphonesimulator IPHONEOS_DEPLOYMENT_TARGET=13.0 \
    -arch x86_64 -arch arm64 -arch i386 \
    BUILD_LIBRARY_FOR_DISTRIBUTION=YES \
    -scheme "aiAnalytics" \
    -archivePath "./build/iphonesimulator/aiAnalytics.xcarchive" SKIP_INSTALL=NO

echo "Building XCFramework with iOS and iOS Simulator support..."
xcodebuild -create-xcframework -output ./aiAnalytics.xcframework \
    -framework "./build/iphoneos/aiAnalytics.xcarchive/Products/Library/Frameworks/aiAnalytics.framework" \
    -framework "./build/iphonesimulator/aiAnalytics.xcarchive/Products/Library/Frameworks/aiAnalytics.framework"

xcodebuild -create-xcframework -output ./aiAnalytics_Pods.xcframework \
    -framework "./build/iphoneos/aiAnalytics.xcarchive/Products/Library/Frameworks/Pods_aiAnalytics.framework" \
    -framework "./build/iphonesimulator/aiAnalytics.xcarchive/Products/Library/Frameworks/Pods_aiAnalytics.framework"
