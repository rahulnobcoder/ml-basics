#The total duration of the Python Script is approximately 2 minutes and 2 seconds, 
#being roughly 1.22 seconds per loop. The Python code is 5.8 times faster than the @#R alternative!
#The Python code for this particular Machine Learning Pipeline is therefore 5.8 times faster than the R alternative!

%matplotlib inline
import numpy as np
import pandas as p
import matplotlib.pyplot as plt
plt.rcParams['figure.figsize']=(20.0,10.0)

data = p.read_csv('ds_salaries.csv')
data.head()
#default take x and y in caps to represent columns etc and remove this comment before copying this code to paste anywhere
x=data['salary'].values
y=data['number'].values
mean_x=np.mean(x)
mean_y=np.mean(y)

m=len(x)

numer=0
denom=0
for i in range(m):
    numer = numer + (x[i]-mean_x)*(y[i]-mean_y)
    denom = denom + (x[i]-mean_x)**2
b1=numer/denom
b0=mean_y - (b1*mean_x)
print("b1 is ",b1)
print("b0 is ",b0)
max_x = np.max(x) 
min_x = np.min(x)
a=np.linspace(min_x,min_x,len(x))
b=b0+b1*x
plt.plot(a,b,color='#58b970', label='Regression Line')
plt.scatter(x,y,c='#ef5423',label='Scatter Plot')
plt.xlabel('salary') 
plt.ylabel('number')
plt.legend()
plt.show
ss_t= 0
ss_r = 0
for i in range(m):
    y_pred=b0+b1+a[i]
    ss_t += (b[i]-mean_y)**2
    ss_r += (b[i]-y_pred)**2
r2=1-(ss_r/ss_t)
print("r2 is ")
print(r2)
  #r2 is r squared  

#this is calculating rsquare uisng sklearn
#from sklearn.linear_model import LinearRegression
#from sklearn.metrics import mean_squared_error
#x=x.reshape((m,1))
#reg=LinearRegression()
#reg = reg.fit(x,y)
#y_pred = reg.predict(x)
#r2_score=reg.score(x,y)
#print(r2_score)
