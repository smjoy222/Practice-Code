import requests
import time

# URL
url = "https://api.adsgram.ai/event?record=IiQ3NDFmOTliMS1lZWY0LTQ4YzEtOTk5NS02Yzk2ZDRiOTk1OWQqBTE2MTg4MgUxOTg5NzoGMTc1NDM4QLDNqLgGSgo3NDg0OTgxNzg0UgQyOTk0WhVodHRwczovL3RpbWVmYXJtLmFwcC9iATJqB2FuZHJvaWRyAmVuigEEMTk2OJIBBDY2OTCaAQw4NzcxOS4wMDAwMDCqAQgxLjAwMDAwMLIBATa6AQ0xODIuNDguNzAuMTU2wgECYmQ&type=reward&trackingtypeid=14"

# নির্দিষ্ট বিরতিতে রিকুয়েস্ট পাঠানোর ফাংশন
def send_request():
    try:
        response = requests.get(url)
        if response.status_code == 200:
            print("Request sent successfully!")
        else:
            print(f"Failed to send request. Status code: {response.status_code}")
    except Exception as e:
        print(f"Error: {e}")

# ১০ সেকেন্ড পর পর রিকুয়েস্ট পাঠানো
while True:
    send_request()
#    time.sleep(10)  # ১০ সেকেন্ড বিরতি