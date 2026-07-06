# Last updated: 7/6/2026, 12:00:20 PM
from typing import List
import re

class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        business_order = {"electronics": 0, "grocery": 1, "pharmacy": 2, "restaurant": 3}
        valid = []

        for i in range(len(code)):
            if (code[i] and re.fullmatch(r'[A-Za-z0-9_]+', code[i]) and
                businessLine[i] in business_order and
                isActive[i]):
                valid.append((business_order[businessLine[i]], code[i]))

        valid.sort()
        return [c for _, c in valid]
