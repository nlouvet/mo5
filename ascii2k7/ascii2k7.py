#!/usr/bin/env python3 

import argparse

def prep_code(infile):
	code = b''
	for line in infile:
		#line = line.upper().strip()
		line = line.strip()
		print(line)
		code += (line.encode('ascii') + b'\x0d')
	return code

def checksum(code):
	c = 0
	for w in code:
		c = (c + w) % 256
	return c

def synchro():
	return b'\x01' * 16 + b'\x3c\x5a'

def heading_bloc(name, ext):
	bloc = b''
	bloc += b'\x00'     # bloc type is "heading"
	bloc += b'\x10'     # bloc length is 16 = \x10
	data = b''
	data += '{:8s}'.format(name).encode('ascii') # file name
	data += '{:3s}'.format(ext).encode('ascii')  #file extension
	data += b'\x00'     # file type: 00=Basic 01=Data 02=Binaire
	data += b'\xff'     # file mode: 00=Binaire FF=Texte
	data += b'\xff'     # same byte as the previous one
	bloc += data
	bloc += (256 - checksum(data)).to_bytes(1, 'little')
	return bloc

def ending_bloc():
	code = b''
	# bloc type is "ending"
	code += b'\xff'
	# bloc length is 2 = \x02
	code += b'\x02'
	# checksum is 0
	code += b'\x00'   
	return code 


def file_bloc(data):
	bloc = b''
	# bloc type is "file content"
	bloc += b'\x01'
	# bloc length
	bloc += ((len(data) + 2) % 256).to_bytes(1, 'little')
	# bloc content
	bloc += data
	# checksum
	bloc += (256 - checksum(data)).to_bytes(1, 'little')
	return bloc

def file_blocs(data):
	code = b''
	l = len(data)
	i = 0
	j = 254
	while j < l:
		tmp = data[i:j]
		code += synchro()
		code += file_bloc(tmp)
		i += 254
		j += 254
	if i < l:
		tmp = data[i:l]
		code += synchro()
		code += file_bloc(tmp)
	return code

def cvt(infile, name, ext):
	outcode = b''
	outcode += synchro()
	outcode += heading_bloc(name, ext)
	outcode += file_blocs(prep_code(infile))
	outcode += synchro()
	outcode += ending_bloc()
	return outcode

if __name__ == '__main__':
	ap = argparse.ArgumentParser()
	ap.add_argument('infile')
	ap.add_argument('outfile')
	args = ap.parse_args()
	print(f'Input file name : {args.infile}')
	print(f'Output file name: {args.outfile}')

	try:
		infile = open(args.infile, 'r')
		outfile = open(args.outfile, 'wb')
	except Exception as err:
		print(err)
		exit(1)
	
	outcode = cvt(infile, 'TEST', 'BAS')
	for i in range(len(outcode)):
		print(hex(outcode[i]))
	outfile.write(outcode)

	infile.close()
	outfile.close()
	
	exit(0)

