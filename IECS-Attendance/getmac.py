import uuid
address = hex(uuid.getnode())[2:]
print('-'.join(address[i:i+2] for i in range(0, len(address), 2)))
