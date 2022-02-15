# bigint
В данном задании вам необходимо реализовать класс длинного знакового числа.

## Требования к реализации

Класс должен называться `big_integer`, а код вашего решения должен находиться в файлах `big_integer.h` и `big_integer.cpp`.

Реализация должна удовлетворять следующим требованиям:
- Умножение и деление должны работать не хуже, чем за O(nm).
- Остальные операции должны производиться с максимально возможной асимптотической эффективностью.
- Помимо асимптотики, стоит уделить внимание оптимизации количества аллокаций и общего времени работы.
- Разряды числа должны представляться как минимум 32-битными числами, все биты в их представлении должны использоваться.
- Пользоваться сторонними библиотеками при выполнении задания запрещено.
- `big_integer` должен уметь создаваться от числовых типов сохраняя значение. Если переменная числового типа имела значение `x`, значит `big_integer` после создания должен иметь значение `x`.
- Время прохождения тестов в сборке в релизе не должно превышать 1 секунду в Release-сборке, при этом ваше решение должно укладываться в лимит при каждом перезапуске.

## Битовые операции для длинных чисел

Для битовых операций можно думать о `big_integer`'ах, как о числа бесконечной битности. Например, число `11` можно представить в двоичной записи как `11 = 000..0001011`, при этом оно содержит бесконечное
число нулей в старших разрядах. Аналогично число `-6` представимо как `-6 = 111..1111010`, где в старших разрядах хранится бесконечное число единиц. Битовые операции определены побитово то есть:

```
c == a & b   <=>   forall n ∈ [0..+∞) (n-тый бит c) == (n-тый бит a) & (n-тый бит b)
```

Таким образом `11 & -6 = 000..0001011 & 111..1111010 = 00..001010 = 10`.

Аналогично битовые операции можно определить для битовых `or`, `xor`, `not` и сдвигов.
