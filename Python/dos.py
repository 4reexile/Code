from scapy.all import *
import random

class PacketGenerator:
    def __init__(self, dest_ip, total_packets):
        self.dest_ip = dest_ip
        self.total_packets = total_packets
        self.starting_with_192_packets = 0

    def generate_packet(self):
        for _ in range(self.total_packets):
            # 随机生成后三个随机化的IP数据包
            src_ip = ".".join(str(random.randint(1, 255)) for _ in range(3))

            # 构造数据包
            pkt = IP(dst=self.dest_ip, src=src_ip) / ICMP()

            # 发送数据包
            send(pkt)

            # 统计以 "192.168.1." 为源IP开头的数据包数量
            if src_ip.startswith("192.168.1."):
                self.starting_with_192_packets += 1

        # 输出以 "192.168.1." 为源IP开头的数据包总数量
        print(f"以 192.168.1. 为源IP开头的数据包总数量：{self.starting_with_192_packets}")

if __name__ == "__main__":
    dest_ip = "10.33.3.152"
    total_packets = 10000  # 发送的总数据包数量

    generator = PacketGenerator(dest_ip, total_packets)
    generator.generate_packet()