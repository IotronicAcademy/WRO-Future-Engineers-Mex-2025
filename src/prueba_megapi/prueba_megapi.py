import serial
import time

# Variables de configuración
puerto = '/dev/ttyUSB0'  # Cambia esto según tu dispositivo
baudrate = 115200

try:
    print(f"Conectando a la MegaPi en {puerto} a {baudrate} baudios...")
    mega = serial.Serial(puerto, baudrate, timeout=1)
    time.sleep(2)  # Esperar que la conexión se establezca

    comando = b'PING\n'
    mega.write(comando)
    print("Comando Enviado:", comando.decode().strip())

    time.sleep(1)

    if mega.in_waiting:
        respuesta = Mega.readline().decode().strip()
        print(f"Respuesta recibida: {respuesta}")
    else:
        print("No se recibió respuesta.")

    mega.close()

except serial.SerialException as e:
    print(f"Error al abrir el puerto serial: {e}")
