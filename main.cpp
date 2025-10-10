#include <algorithm>
#include <iostream>
#include <string>

/** 原理是通过校外登录访问一网通办的方式获取vpn权限
 *  然后通过这个入口登录其他校内网站
 */


using namespace std;

const string atrust_suffix = {"-s.vpn.swpu.edu.cn:8118"};

int find_first_slash(const string& str);
int is_url_have_protocol(const string& str);

int main() {
    cout << "先通过非校园网访问登录一网通办" << endl;
    cout << "https://www.swpu.edu.cn/nic/xxhyy/ywtb.htm" << endl << endl;
    while (true){
    cout << "请输入待访问校内网址：";
    // 读取待转换目标网页
    string aim_websitehande;   // 待转换目标网页
    getline(cin, aim_websitehande);

    // 预处理目标网址
    int slash_pos = find_first_slash(aim_websitehande); // 第一个斜杠位置

    string source_domain = aim_websitehande.substr(0, slash_pos);   // 目标网址的“域名”段
    string source_path = aim_websitehande.substr(slash_pos);    // 目标网址的“路径”段

    // 将目标域名转换为仅包含`-`的域名
    string target_domain = source_domain;
    replace(target_domain.begin(), target_domain.end(), '.', '-');

    // 输出转换后的目标网址
    cout << "转换后的目标网址：";
    cout << target_domain << atrust_suffix << source_path << endl << endl;
    }
    cout << "按任意键退出" << endl;
    getchar();

    return 0;

}

/**
 * @brief 检查url中是否包含协议(`https`,`http`)
 * @param str 要检查的字符串
 * @return 1表示包含协议，0表示不包含
 */
int is_url_have_protocol(const string& str) {
    // 检查是否以http://或https://开头
    if (str.size() >= 7 && str.substr(0, 7) == "http://") {
        return 1;
    }
    if (str.size() >= 8 && str.substr(0, 8) == "https://") {
        return 1;
    }
    return 0;
}

/**
 * @brief 寻找第一个斜杠，并返回斜杠的位置（排除https和http前缀的斜杠）
 * @param str 目标字符串
 * @return 第一个斜杠的位置，-1表示未找到
 */
int find_first_slash(const string& str) {
    int protocol_len = 0;

    // 检查是否有协议前缀，确定需要跳过的长度
    if (is_url_have_protocol(str)) {
        if (str.substr(0, 5) == "https") {
            protocol_len = 8;  // "https://"长度为8
        } else {
            protocol_len = 7;  // "http://"长度为7
        }
    }

    // 从协议后面开始查找第一个斜杠
    for (int i = protocol_len; i < str.size(); i++) {
        if (str[i] == '/') {
            return i;
        }
    }
    return -1;
}

