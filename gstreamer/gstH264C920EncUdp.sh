gst-launch-1.0 -v -e uvch264src rate-control=2 fixed-framerate=true initial-bitrate=250000 average-bitrate=250000 iframe-period=1000 device="/dev/video0" name=src auto-start=true src.vfsrc ! queue ! video/x-raw,format=YUY2,width=160,height=90,framerate=5/1 ! fakesink src.vidsrc ! queue ! video/x-h264,width=1024,height=576,framerate=30/1 ! h264parse ! rtph264pay config-interval=10 pt=96 ! udpsink host=192.168.137.1 port=9000
