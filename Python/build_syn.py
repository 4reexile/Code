from scapy.all import *
import argparse

# syn扫描

def syn_scan(target_ip, target_port):
    ip = IP(dst=target_ip)
    syn = TCP(sport=RandShort(), dport=target_port, flags="S", seq=12345)
    response = sr1(ip / syn, timeout=1, verbose=0)
    if response:
        if response.haslayer(TCP):
            if response.getlayer(TCP).flags == 0x12:
                send_rst = sr(IP(dst=target_ip) / TCP(sport=syn.dport, dport=syn.sport, flags="R"), timeout=1,
                              verbose=0)
                print(f"Port {target_port} is open")
            elif response.getlayer(TCP).flags == 0x14:
                print(f"Port {target_port} is closed")
    else:
        print(f"Port {target_port} is filtered")


# 创建命令行参数解析器
parser = argparse.ArgumentParser(description='SYN Port Scanner.')
parser.add_argument('-H', '--host', help='Target host address', required=True)
parser.add_argument('-p', '--ports', help='Ports to scan, separated by commas', required=True)

# 解析命令行参数
args = parser.parse_args()

# 对给出的每个端口都执行扫描
port_list = [int(port) for port in args.ports.split(',')]
for port in port_list:
    syn_scan(args.host, port)

print("07-曹颢瀚")