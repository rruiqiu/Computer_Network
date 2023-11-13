import math
offerd_load = 2
num_channel = 3
t = 60
h=30
def factorial_iterative(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result
  
def sigma(first,last,const):
  sum =0.0
  for i in range(first,last):
    # print(i)
    sum += (float(pow(const,i))/float(factorial_iterative(i))) 
  return sum

with open('example.txt', 'w') as file:
  for i in range(num_channel,21):
    a = float(pow(offerd_load,i))/float(factorial_iterative(i))
    p=offerd_load/num_channel
    sig_ma = float(sigma(0,i,offerd_load))
    # print(p, sig_ma, a)
    Pb = (a)/(a+(1-p)*sig_ma)
    # print(Pb, "num_channel is ", i, "\n")
    

    
    exp = math.exp(-(num_channel-offerd_load)*t/h)
    W_t = 1-Pb*exp
    print("W_t is", W_t, "the t is:", t)
    print(f"{Pb:.10f} num_channel is {i:.10f}\n")
    
    file.write(f"W_t is {W_t:.10f} num_channel is {i:.10f} \n")
