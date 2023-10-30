Pod::Spec.new do |spec|

  spec.name         = "aiAnalytics"
  spec.version      = "0.0.1"
  spec.summary      = "ai based analytics tool"

  spec.description  = <<-DESC
			ai based analytics tools helps you understand deeper insights 
About your product                   
DESC

  spec.homepage     = "https://github.com/DMS30"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "DMS30" => "shanmukhdm3011@gmail.com" }

  spec.ios.deployment_target = "11.0"
  spec.swift_version = "4.2"

  spec.source        = { :git => "https://github.com/DMS30/aiAnalytics.git", :tag => "#{spec.version}" }
  spec.source_files  = "aiAnalytics/**/*.{h,m,swift}"
  spec.dependency "PostHog", '2.0.5'

end

