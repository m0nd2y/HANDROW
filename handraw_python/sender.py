import sys
import requests
url = 'http://dimi.c2w2m2.com/api/drawpos'

x = int(sys.argv[1])
y = int(sys.argv[2])

data = {'x':x,'y':y}
requests.post(url, data=data)