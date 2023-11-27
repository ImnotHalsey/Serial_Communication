import machine, time, ubinascii, network, urequests, ujson
from machine import Pin

uart = machine.UART(1, baudrate=9600, tx=17, rx=16)  

def connect_to_wifi(ssid, password): # ---> # Connect to wifi
    sta_if = network.WLAN(network.STA_IF)
    if not sta_if.isconnected():
        print('Connecting to Wi-Fi...')
        sta_if.active(True)
        sta_if.connect(ssid, password)
        while not sta_if.isconnected():
            return True
    else:
        print('Connected to Wi-Fi')
        print('Network Config:', sta_if.ifconfig())
        return True

def get_api_data(api_url): #--> # Get the Firmware
    print("Getting firmware is going on ...")
    response = urequests.get(api_url)
    firmware = response.content
    return firmware

def send_data(data): # --> Sends data through RX and TX
    uart.write(data)
    print(f"Sent: {data}")

def reset_mega(mega_reset_pin): # --> Reset MEGA
    mega_reset = Pin(mega_reset_pin, Pin.OUT)
    print("Reset Pulse Given")
    mega_reset.value(1)
    time.sleep(0.5)
    print("Reset Pulse End")
    mega_reset.value(0)
    time.sleep(10)
    return True

def enter_programming_mode(): # --> Mega programming code
    print("Programming mode entered")
    uart.write(b'G')  
    time.sleep(2)  

def main_function():
        connect_to_wifi("FARMROBO_2G", "powertiller1") 
        api_data = get_api_data("https://farmrobo.chaithanyasaipo.repl.co/post_update")
        if api_data:
            reset_mega(2)
            send_data(api_data)
            enter_programming_mode()

while 1:
    main_function()
    time.sleep(5)




