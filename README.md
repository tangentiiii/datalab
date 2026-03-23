# Data Lab

## 题目列表

### 整数操作 (Integer Operations)

| 函数 | 描述 | 难度 |
|------|------|------|
| `bitXor` | 仅用 ~ 和 & 实现异或 | 1 |
| `tmin` | 返回最小补码整数 | 1 |
| `isTmax` | 判断是否为最大补码数 | 1 |
| `allOddBits` | 判断所有奇数位是否为1 | 2 |
| `negate` | 返回相反数 | 2 |
| `isAsciiDigit` | 判断是否为 ASCII 数字字符 (0x30-0x39) | 3 |
| `conditional` | 实现三元运算符 x ? y : z | 3 |
| `isLessOrEqual` | 判断 x <= y | 3 |
| `logicalNeg` | 用除 ! 外的操作符实现 ! 运算符 | 4 |
| `howManyBits` | 返回表示 x 所需的最少位数 | 4 |

### 浮点数操作 (Floating Point Operations)

| 函数 | 描述 | 难度 |
|------|------|------|
| `floatScale2` | 返回 2*f 的位级等价 | 4 |
| `floatFloat2Int` | 返回 (int)f 的位级等价 | 4 |
| `floatPower2` | 返回 2.0^x 的位级等价 | 4 |

## 运行方法

### 1. 编译测试程序

```bash
make
```

这会生成三个程序：
- `btest` - 测试函数正确性
- `fshow` - 显示浮点数结构
- `ishow` - 显示整数结构

### 2. 测试你的解答

运行所有测试：
```bash
./btest
```

测试特定函数：
```bash
./btest -f bitXor
./btest -f isAsciiDigit
```

显示帮助信息：
```bash
./btest -h
```

### 3. 检查代码规范

使用 dlc 编译器检查你的代码是否符合规范（操作符限制等）：
```bash
./dlc bits.c
```

### 4. 运行完整评分程序

使用 driver.pl 进行完整评分（正确性 + 性能）：
```bash
./driver.pl
```

评分会输出每个函数的得分和总分数。

## 代码规范

整数操作规则：
- 只能使用常量 0-255
- 只能使用函数参数和局部变量
- 允许的操作符：`! ~ & ^ | + << >>`
- 禁止：if、while、for、switch 等控制语句；宏；额外函数；类型转换

浮点数操作规则：
- 允许使用 looping 和 conditionals
- 允许使用任意整数和 unsigned 常量
- 禁止：宏、额外函数、类型转换、float 类型

## 文件说明

- `bits.c` - 你的解答文件（需要编辑）
- `bits.h` - 函数声明
- `btest.c` / `btest.h` - 测试框架
- `dlc` - 数据实验室编译器（检查代码规范）
- `driver.pl` - 完整评分脚本
- `tests.c` - 测试用例
