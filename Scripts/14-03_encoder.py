import sys

#decode
#1. convert first two chars to cypherIndex
#2. use cypherIndex to get subChar
#3. append subChar to result

subCypher = "/abcdefghijklmnopqrstuvwxyz0123456789:."

def encode(source):
    encodedMsg = list()
    #1. iterate through source char
    for c in source:
        #2. for each source char, find index in subCypher
        cypherIndex = subCypher.find(c)
        #3. convert each # index to a string
        indexStr = str(cypherIndex)
        if cypherIndex < 10:
            indexStr = f"0{indexStr}"
        #4. add string to final msg
        encodedMsg.append(indexStr)
    return ''.join(encodedMsg)


if __name__ == "__main__":
    source = sys.argv[1]
    dest = encode(source)
    print(dest)
