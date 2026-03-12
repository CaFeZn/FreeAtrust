# 🔐 西南石油大学 VPN 地址转换工具

一个简单实用的工具，帮助西南石油大学师生通过校园网免登录访问外网资源。

## ✨ 功能特点

- 🌐 **网页版**：无需安装，打开即用
- 🚀 **快速转换**：一键将普通网址转换为校园VPN地址
- 📋 **一键复制**：转换后可直接复制使用
- 📝 **历史记录**：自动保存最近10条转换记录
- 📱 **响应式设计**：支持手机、平板、电脑等各种设备
- 💾 **本地存储**：历史记录保存在本地，隐私安全

## 🎯 使用方法

### 使用步骤

1. **先登录 WebVPN**：访问 [一网通办非校园网访问](https://www.swpu.edu.cn/nic/xxhyy/ywtb.htm) 页面，点击按钮登录 WebVPN
2. **转换网址**：使用本工具将目标网址转换为 VPN 地址
3. **访问目标网站**：使用转换后的地址访问目标网站

⚠️ **注意**：必须先登录 WebVPN，转换后的地址才能正常使用

### 在线使用

直接访问：[https://cafezn.github.io/FreeAtrust/](https://cafezn.github.io/FreeAtrust/)

### 本地使用

1. 克隆或下载本项目
2. 直接用浏览器打开 `index.html` 文件即可

## 📖 转换原理

该工具的转换原理非常简单：

1. 提取目标网址的域名部分
2. 将域名中的所有 `.` 替换为 `-`
3. 添加西南石油大学VPN后缀：`-s.vpn.swpu.edu.cn:8118`
4. 拼接原始路径

**示例：**

```text
输入：www.example.com/path/to/page
输出：https://www-example-com-s.vpn.swpu.edu.cn:8118/path/to/page
```

## 🚀 部署到 GitHub Pages

1. Fork 或上传本项目到你的 GitHub 仓库
2. 进入仓库的 Settings → Pages
3. 在 Source 中选择 `main` 分支
4. 点击 Save，等待几分钟即可访问

## 💻 C++ 命令行版本

本项目同时提供 C++ 命令行版本，适合在终端中使用。

### 编译方法

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### 运行

```bash
./atrust_SWPU
```

## 📋 系统要求

- **网页版**：任何现代浏览器（Chrome、Firefox、Safari、Edge等）
- **C++版本**：
  - CMake 3.15+
  - C++20 支持的编译器
  - 支持 Windows、macOS、Linux

## 🔗 相关链接

- [西南石油大学网络信息中心](https://www.swpu.edu.cn/nic/)
- [业务通报](https://www.swpu.edu.cn/nic/xxhyy/ywtb.htm)

## ⚠️ 注意事项

1. **必须先登录**：使用前必须先访问 [一网通办非校园网访问](https://www.swpu.edu.cn/nic/xxhyy/ywtb.htm) 登录 WebVPN
2. 本工具仅供西南石油大学师生使用
3. 请遵守学校网络使用规定
4. 转换后的地址需要在登录 WebVPN 后才能访问
5. 历史记录保存在浏览器本地，清除浏览器数据会丢失历史记录

## 📄 开源协议

本项目采用 MIT 协议开源，欢迎贡献代码和提出建议。

## 🤝 贡献

欢迎提交 Issue 和 Pull Request！

## 📧 联系方式

如有问题或建议，欢迎通过 GitHub Issues 反馈。

---

Made with ❤️ for SWPU Students
