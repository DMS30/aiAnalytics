Pod::Spec.new do |spec|

  spec.name         = "aiAnalytics"
  spec.version      = "0.0.2"
  spec.summary      = "ai based analytics tool"

  spec.description  = <<-DESC
			ai based analytics tools helps you understand deeper insights 
About your product                   
DESC

  spec.homepage     = "https://github.com/DMS30"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "DMS30" => "shanmukhdm3011@gmail.com" }

  spec.ios.deployment_target = "11.0"
  spec.swift_version = "5"
  spec.ios.frameworks = 'CoreTelephony'
  spec.frameworks = 'Security', 'StoreKit', 'SystemConfiguration', 'UIKit'

  spec.source        = { :git => "https://github.com/DMS30/aiAnalytics.git", :tag => "#{spec.version}" }
  spec.source_files  = "aiAnalytics/**/*.{h,m,swift}"

end

