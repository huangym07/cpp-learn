## 环境与编译工具

Windows11

gcc 13.2.0

## 项目构建

### StrVec

StrVec 是对 std::vector\<std::string\> 的简化仿写

include/StrVecLib: StrVec 头文件
src/StrVecLib: StrVec 的实现代码以及 CMakeLists.txt  

使用 Google Test 框架对 StrVec 进行单元测试

构建方式如下：

```bash
# 项目根目录下
mkdir build && cd build
cmake -G "Unix Makefiles" ..
make

# 运行
ctest
```