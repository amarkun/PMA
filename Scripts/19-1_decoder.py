import sys

def decode(enc, code):
    i = 0
    dec = list()
    while (i+1) < len(enc):
        first = enc[i]
        print(f'First: {first}')
        second = enc[i+1]
        print(f'Second: {second}')
        new = ((ord(first) - ord(code)) << 4) + (ord(second) - ord(code))
        print(f'New: {new}')
        print(f'New hex: {hex(new)}')
        print()
        dec.append(hex(new))
        i+=2
    return dec
        

if __name__ == "__main__":
    enc = sys.argv[1]
    code = sys.argv[2][0]
    dec = decode(enc, code)
    print(dec)