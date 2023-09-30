#include <graphics/wvk/wvk_context.hxx>
#include <iostream>

class VulkanApp {
  wvk::Context context;
public:
  VulkanApp() {
    context.createContext();
  }

  ~VulkanApp() {
    context.destroyContext();
  }
  
  void run() {
    std::cout << "Vulkan Context Created" << std::endl;
  }
};

int main() {
  VulkanApp app{};
  
  app.run();
  
  return 0;
}