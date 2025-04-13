def main():
    n = int(input())
    
    even_orders = []
    odd_orders = []
    
    for _ in range(n):
        s = str(input())
        even = 0
        odd = 0
        for i, ch in enumerate(s):
            if ch == 'S':
                if i % 2 == 0:
                    even += 1
                else:
                    odd += 1
        if len(s) % 2 == 0:
            even_orders.append((even, odd))
        else:
            diff = even - odd
            odd_orders.append((even, odd, diff))
    
    total = 0
    if odd_orders:
        r = (len(odd_orders) + 2 - 1) // 2
        odd_orders.sort(key=lambda x: x[2], reverse=True)

        odd_total = 0
        for i in range(len(odd_orders)):
            if i < r:
                odd_total += odd_orders[i][0] # first half best orders takes Vasya
            else:
                odd_total += odd_orders[i][1] # second half best orders takes Masha, so Vasya takes what's left

        total += odd_total

        even_total = 0
        for even_orders_v, even_orders_m in even_orders:
            even_total += max(even_orders_v, even_orders_m)
    else:
        even_total = 0
        for even_orders_v, even_orders_m in even_orders:
            even_total += even_orders_v 
    
    total += even_total
    print(total)
    return


if __name__ == '__main__':
    main()