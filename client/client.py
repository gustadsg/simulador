import os
import struct
import subprocess

processo_servidor = subprocess.Popen("../server/bin/server", shell=True)


pipe_path = "/tmp/server_pipe"
struct_format = "ii"

pipe = os.open(pipe_path, os.O_RDONLY)

data = os.read(pipe, struct.calcsize(struct_format))

data_tuple = struct.unpack(struct_format, data)

print(data_tuple)

os.close(pipe)

