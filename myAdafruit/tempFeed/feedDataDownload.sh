#!/bin/bash

API_KEY="aio_upMS014n0bTL6fsMyBHcJlcPITIZ"
#USERNAME="CamGrav"
#FEED_KEY="weather.teperature"
OUTPUT_FILE="feed_data_JSON.csv"

curl -H "X-AIO-Key: $API_KEY" "https://io.adafruit.com/api/v2/CamGrav/feeds/weather.temperature/data?include=value&format=csv" -o $OUTPUT_FILE

echo "Data downloaded to $OUTPUT_FILE"
