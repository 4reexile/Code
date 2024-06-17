import argparse
from scapy.all import conf, sr1, IP, ICMP


def ping_host(base, dst_ip_range):
    # 创建 ICMP 数据包
    for i in dst_ip_range:
        dst_ip = base + str(i)
        pkt = IP(dst=dst_ip) / ICMP()

        response = sr1(pkt, timeout=1)

        if response:
            print("目标 IP 地址 {} 存活".format(dst_ip))


# 创建命令行参数解析器
parser = argparse.ArgumentParser(description='Ping a range of hosts.')
parser.add_argument('-b', '--base', help='Base IP address', required=True)
parser.add_argument('-d', '--destination', nargs=2, type=int, help='Destination IP address range. Input two integers',
                    required=True)
# 关闭 Scapy 的冗余信息输出
conf.verb = 0
# 解析命令行参数
args = parser.parse_args()
base = args.base if args.base.endswith('.') else args.base + '.'
ping_host(base, range(args.destination[0], args.destination[1] + 1))