import random
import time

def generate_random_data(filename):
    while True:
        with open(filename, 'a') as file:
            data = random.randint(-10000, 10000)
            file.write(f"{data}\n")
            print(f"Written data: {data}")
        time.sleep(2)

if __name__ == "__main__":
    generate_random_data("data.txt")
