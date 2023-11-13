offerd_load = 10
num_channel = 1

def factorial_iterative(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result
  
def sigma(first,last,const):
  sum =0.0
  for i in range(first,last+1):
    # print(i)
    sum += (float(pow(const,i))/float(factorial_iterative(i))) 
  return sum

with open('example.txt', 'w') as file:
  for i in range(num_channel,21):
    Pb = (float(pow(offerd_load,i))/float(factorial_iterative(i)))/float(sigma(0,i,offerd_load))
    # print(Pb, "num_channel is ", i, "\n")
    print(f"{Pb:.10f} num_channel is {i:.10f}\n")
    file.write(f"{Pb:.10f} num_channel is {i:.10f}\n")
