from datetime import datetime
import pytz

# Set the time zone to Indian Standard Time
india_timezone = pytz.timezone('Asia/Kolkata')

# Get the current time in UTC
utc_now = datetime.utcnow()

# Convert the UTC time to Indian Standard Time
ist_now = utc_now.replace(tzinfo=pytz.utc).astimezone(india_timezone)

# Format and print the time
formatted_time = ist_now.strftime('%Y-%m-%d %H:%M:%S %Z')
print(f"Current time in India (IST): {formatted_time}")
