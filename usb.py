import serial
ser = serial.Serial('/dev/ttyACM0', 9600)

value_list = []
while True: 
    values = f"{ser.readline()}"
    values = values.replace("b'", "").replace("\\r", "").replace("\\n", "")
    print(values)
    value_list.append(values)

