def solution(S, K):
    # input: S = weekday, K = days after
    # Example "Wed" + 2 = "Fri"
    # Simple modulo calculation will do.
    # simpler with list instead of dict.
    days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
    
    index = -1
    for i in range(len(days)):
        if days[i] == S:
            index = i
            break
    
    return days[(index+K)%7]

print(solution("Mon", 500))