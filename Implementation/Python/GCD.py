def greatest_common_divider(a, b):
    while a != b:
        if a > b:
            a  =  a - b
        else:
            b = b - a
    return a

def main():
    a = 20 
    b = 50
    print(greatest_common_divider(a, b))

if __name__ == "__main__":
    main()
 