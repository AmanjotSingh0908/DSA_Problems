import math

def main():
    N, F = map(int, input().split())
    current_node = 1
    for _ in range(F):
        file_info = input().split()
        file_name = file_info[0]
        file_size = int(file_info[1])
        replication_factor = int(file_info[2])
        num_chunks = math.ceil(file_size / 64)
        print(f"File {file_name}:")
        for chunk in range(1, num_chunks + 1):
            nodes = []
            for _ in range(replication_factor):
                nodes.append(f"Node {current_node}")
                current_node += 1
                if current_node > N:
                    current_node = 1
            print(f"Chunk {chunk}: " + " ".join(nodes))

if __name__ == "__main__":
    main()
