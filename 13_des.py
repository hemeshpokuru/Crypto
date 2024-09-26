from Crypto.Cipher import DES
from Crypto.Random import get_random_bytes
import base64

# Padding function (DES requires data to be a multiple of 8 bytes)
def pad(text):
    while len(text) % 8 != 0:
        text += ' '
    return text

# Encryption
def des_encrypt(plain_text, key):
    des = DES.new(key, DES.MODE_ECB)  # Create a new DES cipher object in ECB mode
    padded_text = pad(plain_text)  # Pad the plain text to be a multiple of 8 bytes
    encrypted_text = des.encrypt(padded_text.encode('utf-8'))  # Encrypt the padded text
    return base64.b64encode(encrypted_text).decode('utf-8')  # Encode in base64 to make it printable

# Decryption
def des_decrypt(encrypted_text, key):
    des = DES.new(key, DES.MODE_ECB)  # Create a new DES cipher object in ECB mode
    decrypted_text = des.decrypt(base64.b64decode(encrypted_text))  # Decrypt the encrypted text
    return decrypted_text.decode('utf-8').rstrip()  # Remove padding spaces

# Main function
if __name__ == '__main__':
    # Generate a random 8-byte DES key
    key = get_random_bytes(8)
    print(f"DES Symmetric Key (hex): {key.hex()}")

    # Get the message to encrypt
    plain_text = input("Enter the message to encrypt: ")

    # Encrypt the message
    encrypted_text = des_encrypt(plain_text, key)
    print(f"Encrypted Message: {encrypted_text}")

    # Decrypt the message
    decrypted_text = des_decrypt(encrypted_text, key)
    print(f"Decrypted Message: {decrypted_text}")
