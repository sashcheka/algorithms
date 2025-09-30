hs, hw, sw, v0, v1, v2 = map(int, input().split())

temp_hs = hs
temp_hw = hw
temp_sw = sw
hs = min(temp_hs, temp_hw + temp_sw)
hw = min(temp_hw, temp_hs + temp_sw)
sw = min(temp_sw, temp_hs + temp_hw)

# home - shop - home - wb - home
hshwh = hs/v0 + hs/v1 + hw/v0 + hw/v1

# home - shop - wb - home
hswh = hs/v0 + sw/v1 + hw/v2

# home - wb - shop - home
hwsh = hw/v0 + sw/v1 + hs/v2

print(min(hshwh, hswh, hwsh))