import hashlib

def bytes_to_hex(byte_data):
    # Convert byte data to hexadecimal string
    return ''.join(['{:02x}'.format(byte) for byte in byte_data])

def sha1_hash(input_string):
    # Create a new SHA-1 hash object
    sha1 = hashlib.sha1()
    
    # Update the hash object with the input string (encode it to bytes)
    sha1.update(input_string.encode('utf-8'))
    
    # Get the hexadecimal digest of the hash
    return bytes_to_hex(sha1.digest())

def main():
    # Input strings to hash
    input1 = ""
    input2 = "abc"
    input3 = "abcdefghijklmnopqrstuvwxyz"
    
    # Print the SHA-1 hash for each input
    print(f"SHA1(\"{input1}\") = {sha1_hash(input1)}")
    print(f"SHA1(\"{input2}\") = {sha1_hash(input2)}")
    print(f"SHA1(\"{input3}\") = {sha1_hash(input3)}")

if __name__ == "__main__":
    main()
