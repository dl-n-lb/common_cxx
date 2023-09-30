#ifndef WVK_CONTEXT_HXX_
#define WVK_CONTEXT_HXX_

#include <vulkan/vulkan_core.h>
#define VULKAN_HPP_NO_CONSTRUCTORS
#include <vulkan/vulkan.hpp>
#include "../../types/type_alias.hxx"

/* FIXME:
 - createContext accepts some parameters
 - choose some physical device other than 0 (perhaps some scoring system?)
 - debug utils messenger using vk::StructureChain
 - somehow opt in/out of debug
*/
namespace wvk {
  
struct ContextCreateInfo {
  str appName = "No name";
  str engineName = "No Engine";
  u32 apiVersion = VK_API_VERSION_1_3;
};

struct Context {
  vk::Instance instance;
  vk::PhysicalDevice physicalDevice;
  vk::Device device;
  
  vk::PhysicalDeviceProperties physicalDeviceProps;
  vk::PhysicalDeviceFeatures physicalDeviceFeatures;
  vk::PhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;
  
  bool active = false;
  
  void createContext(const str& appName, 
    const str& engineName, u32 apiVersion);
  void createContext(const ContextCreateInfo& info = {});
  void destroyContext();
  
  Context() = default;
  
  // There should only be one context per app realistically
  Context(const Context&) = delete;
  Context(Context&&) = delete;
  Context operator=(const Context& other) = delete;
  
  // Clean up if the user forgets
  ~Context();
};

}

#endif
