#gst-launch-1.0 -v -e v4l2src ! video/x-raw,width=640,height=480,framerate=25/1 ! omxh264enc target-bitrate=1500000 control-rate=variable ! video/x-h264,profile=high ! h264parse ! mpegtsmux ! tcpclientsink host=192.168.137.1 port=8888
#gst-launch-1.0 -v -e v4l2src ! video/x-raw,width=640,height=480,framerate=25/1 ! omxh264enc target-bitrate=1500000 control-rate=variable ! video/x-h264,profile=high ! h264parse ! rtph264pay config-interval=10 pt=96 ! udpsink host=192.168.137.1 port=9000
gst-launch-1.0 v4l2src device = "/dev/video0" ! video/x-raw, width=1280, height=720 ! omxh264enc target-bitrate=1000000 control-rate=variable ! video/x-h264,profile=high ! h264parse ! rtph264pay config-interval=10 pt=96 ! udpsink host=192.168.137.1 port=9000
