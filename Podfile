# Uncomment the next line to define a global platform for your project
 platform :ios, '11.0'

target 'aiAnalytics' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

  # Pods for aiAnalytics
   def shared_testing_pods
      pod 'Quick', '~> 1.2.0'
      pod 'Nimble', '~> 9.2.0'
      pod 'Nocilla', '~> 0.11.0'
      pod 'Alamofire', '~> 4.5'
      pod 'Alamofire-Synchronous', '~> 4.0'
   end

  target 'aiAnalyticsTests' do
    # Pods for testing
  end

  post_install do |installer|
    installer.generated_projects.each do |project|
      project.targets.each do |target|
        target.build_configurations.each do |config|
          config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '11.0'
        end
      end
    end
  end
end



