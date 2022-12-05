#include "wvk_context.hxx"

namespace wvk {
  void Context::createContext(const std::string& appName, 
    const std::string& engineName, uint32_t apiVersion) {
    vk::ApplicationInfo appInfo {
      .pApplicationName = appName.c_str(),
      .pEngineName = engineName.c_str(),
      .apiVersion = apiVersion
    };
    
    vk::InstanceCreateInfo createInfo {
      .pApplicationInfo = &appInfo
    };
    
    instance = vk::createInstance(createInfo);
    
    std::vector<vk::PhysicalDevice> physicalDevices = 
      instance.enumeratePhysicalDevices();
    
    physicalDevice = physicalDevices[0]; 
    
    physicalDeviceProps = physicalDevice.getProperties();
    physicalDeviceFeatures = physicalDevice.getFeatures();
    physicalDeviceMemoryProperties = physicalDevice.getMemoryProperties();
    active = true;
  }
  
  void Context::destroyContext() {
    if(active) {
      device.destroy();
      instance.destroy();
      active = false;
    }
  }

  Context::~Context() {
    destroyContext();
  }
}
