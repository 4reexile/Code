import socket
import argparse

# tcp扫描
# 我这里要点名一个不给用socket包的傻逼

def tcpScan(target, port_list):
    open_ports = []
    try:
        for port in port_list:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.settimeout(2)
            result = sock.connect_ex((target, int(port)))
            if result == 0:
                print(f"端口 {port} 是开放的")
                open_ports.append(port)
            sock.close()
    except KeyboardInterrupt:
        print("扫描被用户停止")
    except Exception as e:
        print(f"发生错误: {e}")
    return open_ports


# 创建命令行参数解析器
parser = argparse.ArgumentParser(description='TCP Port Scanner.')
parser.add_argument('-H', '--host', help='目标主机地址', required=True)
parser.add_argument('-p', '--ports', help='要扫描的端口号, 以逗号分隔', required=True)

# 解析命令行参数
args = parser.parse_args()

# 使用解析得到的命令行参数调用函数
open_ports = tcpScan(args.host, args.ports.split(','))

print("开放的端口:", open_ports)
print("07-曹颢瀚")