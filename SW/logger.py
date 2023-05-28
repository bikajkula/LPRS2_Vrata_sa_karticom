import serial
from datetime import datetime

ser = serial.Serial('COM3', 9600)  # comX slave arduino port


filename = 'log.txt'
file = open(filename, 'w')

while True:
   
    now = datetime.now()
    
    data = ser.readline().decode().strip()
    
    current_time = now.strftime("%d/%m/%Y %H:%M:%S")

    file.write(str(current_time) + '\n' + data + '\n\n')
    file.flush()  


    print(data)

file.close()
ser.close()