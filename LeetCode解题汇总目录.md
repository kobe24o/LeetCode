此篇为学习完[《数据结构与算法之美》](https://michael.blog.csdn.net/article/details/89459835)后，在[LeetCode](https://leetcode.cn/problemset/all/)刷题的汇总目录，方便大家查找（Ctrl+F~ind~），一起刷题，一起PK交流！如果本文对你有帮助，可以给我点赞加油！  Updated on 2022.6.12

刷题可以按照[不同的专题](https://leetcode.cn/leetbook/)进行，便于加强某个知识点的理解。另有[《剑指Offer》面试题（更新完毕）](https://michael.blog.csdn.net/article/details/104271963)、[《程序员面试金典》面试题（更新完毕）](https://blog.csdn.net/qq_21201267/article/details/104306869)、[LintCode代码能力测试CAT](https://blog.csdn.net/qq_21201267/article/details/104603021)。

[LeetCode MySQL 数据库解题目录](https://michael.blog.csdn.net/article/details/107423652)

[点击访问 我的 LeetCode 主页](https://leetcode.cn/u/kobe24o/)

[我的 GitHub 主页](https://github.com/kobe24o/LeetCode)

注：本文超过字数限制，完整版MD文件见[Github](https://github.com/kobe24o/LeetCode/blob/master/LeetCode%E8%A7%A3%E9%A2%98%E6%B1%87%E6%80%BB%E7%9B%AE%E5%BD%95.md)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200613203541502.gif)

**通过2224, 简单679/701, 中等1240/1445, 困难305/576**

- 2019.07.24 - 2019.11.09，AC + 400道（108天）

- 2019.11.09 - 2019.11.24，AC + 100道，共计500道（123天，4个月）

- 2019.11.24 - 2019.12.31，AC +  72 道，共计572道（160天）

- 2020.01.01 - 2020.01.12，AC +  32 道，共计604道（172天）

- 2020.01.12 - 2020.03.25，AC + 196道，共计800道，做了些面试题（245天，8个月）

- 2020.03.25 - 2020.04.19，AC + 100道，共计900道（270天，9个月）

- 2020.04.19 - 2020.05.19，AC + 100道，共计<font color=#FF0000>**1000**</font>道（300天，<font color=#FF0000>**10**</font>个月）

- 2020.05.19 - 2020.05.27，AC +  24 道，共计<font color=#0035FF>**1024**</font>道（程序员的数字<font color=#0035FF> 2^10^ </font> ）

- 2020.05.19 - 2020.06.18，AC + 100道，共计1100道（330天，11个月）

- 2020.06.18 - 2020.07.04，AC + 100道，共计1200道（346天，50周）

- 2020.07.04 - 2020.07.18，AC + 100道，共计1300道（360天）

- 2020.07.18 - 2020.07.23，AC +  50 道，共计<font color=#FF0000>**1350**</font>道（365天，<font color=#FF0000>**刷题1周年**</font>）

  过去一年提交4196次，目前刷题量：全站第46名

  竞赛积分1741，排名：全国1987，全球9027，竞赛最好成绩：前7.51% （记录于2020.7.23）

- 2020.07.23 - 2020.07.29，AC +  50 道，共计1400道（371天）

- 2020.07.29 - 2020.08.14，AC + 100道，共计1500道（387天）

- 2020.08.14 - 2020.10.05，AC + 100道，共计1600道（439天）

| 参赛记录                                                     |
| :----------------------------------------------------------- |
| [LeetCode 2019 力扣杯全国秋季编程大赛（582/1541，前37.7%）](https://blog.csdn.net/qq_21201267/article/details/101345174) |
| [LeetCode 第 16 场双周赛（402/822，前48.9%）](https://michael.blog.csdn.net/article/details/103757611) |
| [LeetCode 第 17 场双周赛（469/897，前52.3%）](https://michael.blog.csdn.net/article/details/103942178) |
| [LeetCode 第 18 场双周赛（188/587，前32%）](https://michael.blog.csdn.net/article/details/104087738) |
| [LeetCode 第 19 场双周赛（231/1120，前20.6%）](https://michael.blog.csdn.net/article/details/104230340) |
| [LeetCode 第 20 场双周赛（294/1541，前19.1%，第1次全部通过🚀）](https://michael.blog.csdn.net/article/details/104453219) |
| [LeetCode 第 21 场双周赛（779/1913，前40.7%）](https://michael.blog.csdn.net/article/details/104725634) |
| [LeetCode 第 22 场双周赛（220/2041，前10.8%）](https://michael.blog.csdn.net/article/details/105022135) |
| [LeetCode 第 23 场双周赛（970/2044，前47.5%）](https://michael.blog.csdn.net/article/details/105323119) |
| [LeetCode 2020 力扣杯全国春季编程大赛（1644/4093，前40.2%）](https://michael.blog.csdn.net/article/details/105603426) |
| [LeetCode 第 24 场双周赛（326/1898，前17.2%）](https://michael.blog.csdn.net/article/details/105608345) |
| [LeetCode 第 186 场周赛（1060/3107，前34.1%）](https://michael.blog.csdn.net/article/details/105766947) |
| [LeetCode 第 25 场双周赛（718/1832，前39.2%）](https://michael.blog.csdn.net/article/details/105897792) |
| [LeetCode 第 187 场周赛（1336/3107，前43.0%）](https://michael.blog.csdn.net/article/details/105903207) |
| [LeetCode 第 26 场双周赛（363/1971，前18.4%）](https://michael.blog.csdn.net/article/details/106167968) |
| [LeetCode 第 27 场双周赛（1125/1966，前57.2%）](https://michael.blog.csdn.net/article/details/106453232) |
| [LeetCode 第 28 场双周赛（505/2144，前23.6%）](https://michael.blog.csdn.net/article/details/106736232) |
| [LeetCode 第 29 场双周赛（890/2259，前39.4%）](https://michael.blog.csdn.net/article/details/106990467) |
| [LeetCode 第 30 场双周赛（477/2545，前18.7%，第2次全部通过🚀）](https://michael.blog.csdn.net/article/details/107293199) |
| [LeetCode 第 197 场周赛（468/5273，前8.88%）](https://michael.blog.csdn.net/article/details/107297636) |
| [LeetCode 第 198 场周赛（434/5778，前7.51%）](https://michael.blog.csdn.net/article/details/107443611) |
| [LeetCode 第 31 场双周赛（273/2767，前9.87%，第3次全部通过🚀）](https://michael.blog.csdn.net/article/details/107587115) |
| [LeetCode 第 199 场周赛（757/5231，前14.5%）](https://michael.blog.csdn.net/article/details/107591466) |
| [LeetCode 第 32 场双周赛（983/2957，前33.2%）](https://michael.blog.csdn.net/article/details/107892779) |
| [LeetCode 第 201 场周赛（304/5614，前5.42%）](https://michael.blog.csdn.net/article/details/107894840) |
| [LeetCode 第 33 场双周赛（511/3304，前15.5%，第4次全部通过🚀）](https://michael.blog.csdn.net/article/details/108177289) |
| [LeetCode 第 34 场双周赛（385/2842，前13.5%）](https://michael.blog.csdn.net/article/details/108426333) |
| [LeetCode 2020 力扣杯全国秋季编程大赛（656/3244，前20.2%）](https://michael.blog.csdn.net/article/details/108553304) |
| [LeetCode 第 206 场周赛（733/4491，前16.3%）](https://michael.blog.csdn.net/article/details/108561122) |
| [LeetCode 第 35 场双周赛（216/2839，前7.61%）](https://michael.blog.csdn.net/article/details/108688898) |
| [LeetCode 第 207 场周赛（245/4115，前5.95%）](https://michael.blog.csdn.net/article/details/108691909) |
| [LeetCode 第 36 场双周赛（304/2204，前13.8%）](https://michael.blog.csdn.net/article/details/108914842) |
| [LeetCode 第 40 场双周赛（197/1891，前10.4%，第5次全部通过🚀）](https://michael.blog.csdn.net/article/details/110322462) |
| [LeetCode 第 41 场双周赛（283/1660，前17.1%）](https://michael.blog.csdn.net/article/details/111087463) |
| [LeetCode 第 219 场周赛（463/3709，前12.5%）](https://michael.blog.csdn.net/article/details/111139125) |
| [LeetCode 第 222 场周赛（221/3117，前7.09%）](https://michael.blog.csdn.net/article/details/112133125) |
| [LeetCode 第 43 场双周赛（374/1631，前22.9%）](https://michael.blog.csdn.net/article/details/112417953) |
| [LeetCode 第 223 场周赛（265/3871， 前6.85%）](https://michael.blog.csdn.net/article/details/112426296) |
| [LeetCode 第 44 场双周赛（260/1826，前14.2%）](https://michael.blog.csdn.net/article/details/113068427) |
| [LeetCode 第 225 场周赛（947/3851，前24.6%）](https://michael.blog.csdn.net/article/details/113086195) |
| [LeetCode 第 45 场双周赛（322/1676，前19.2%）](https://michael.blog.csdn.net/article/details/113733199) |
| [LeetCode 第 235 场周赛（322/4493，前7.17%）](https://michael.blog.csdn.net/article/details/115427000) |
| [LeetCode 第 237 场周赛（490/4576，前10.7%，第6次全部通过🚀）](https://michael.blog.csdn.net/article/details/115831551) |
| [LeetCode 第 53 场双周赛（139/3069，前4.53%，第7次全部通过🚀）](https://michael.blog.csdn.net/article/details/117393227) |
| [LeetCode 2021 力扣杯全国秋季编程大赛（第384名）](https://michael.blog.csdn.net/article/details/120240901) |

​          

| 已解题目                                                     | 分类系列                                                     |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [LeetCode 1. 两数之和（哈希）](https://blog.csdn.net/qq_21201267/article/details/97125420) | [LeetCode 旋转数组 系列（二分查找）](https://michael.blog.csdn.net/article/details/105783301) |
| [LeetCode 2. 两数相加（单链表反转）](https://blog.csdn.net/qq_21201267/article/details/97191786) | [LeetCode 股票买卖 系列（动态规划） ](https://blog.csdn.net/qq_21201267/article/details/100026086) |
| [LeetCode 3. 无重复字符的最长子串（滑动窗口+哈希）](https://blog.csdn.net/qq_21201267/article/details/102333616) | [LeetCode 丑数 系列（DP/二分）](https://blog.csdn.net/qq_21201267/article/details/103738537) |
| [LeetCode 4. 寻找两个有序数组的中位数（二分查找，难）](https://blog.csdn.net/qq_21201267/article/details/102828858) | [LeetCode 跳跃游戏 系列（贪心/BFS/DP）](https://blog.csdn.net/qq_21201267/article/details/100899698) |
| [LeetCode 5. 最长回文子串（动态规划）](https://michael.blog.csdn.net/article/details/105348936) | [极小极大化 就用 二分查找](https://blog.csdn.net/qq_21201267/article/details/107534172) |
| [LeetCode 6. Z 字形变换（找规律）](https://blog.csdn.net/qq_21201267/article/details/104782401) | [博弈DP、石子游戏等](https://michael.blog.csdn.net/article/details/108337865) |
| [LeetCode 7. 整数反转](https://blog.csdn.net/qq_21201267/article/details/100583336) | [哈希记录前缀和状态，做差求中间段](https://michael.blog.csdn.net/article/details/108593514) |
| [LeetCode 8. 字符串转换整数 (atoi)](https://blog.csdn.net/qq_21201267/article/details/100583821) | [差分思想](https://michael.blog.csdn.net/article/details/106423509) |
| [LeetCode 9. 回文数](https://blog.csdn.net/qq_21201267/article/details/100168231) | [最长上升子序 DP](https://michael.blog.csdn.net/article/details/97308533) |
| [LeetCode 10. 正则表达式匹配（递归）*](https://blog.csdn.net/qq_21201267/article/details/104951143) |                                                              |
| [LeetCode 11. 盛最多水的容器（双指针）](https://blog.csdn.net/qq_21201267/article/details/100545403) |                                                              |
| [LeetCode 12/13 罗马数字与整型互转（哈希，贪心）](https://michael.blog.csdn.net/article/details/103507056) |                                                              |
| [LeetCode 14. 最长公共前缀](https://blog.csdn.net/qq_21201267/article/details/100866922) |                                                              |
| [LeetCode 15. 三数之和](https://blog.csdn.net/qq_21201267/article/details/99241741) |                                                              |
| [LeetCode 16. 最接近的三数之和（固定左端+滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/100863583) |                                                              |
| [LeetCode 17. 电话号码的字母组合（回溯）](https://blog.csdn.net/qq_21201267/article/details/100436281) |                                                              |
| [LeetCode 18. 四数之和（双指针）](https://blog.csdn.net/qq_21201267/article/details/102672839) |                                                              |
| [LeetCode 19. 删除链表的倒数第N个节点（双指针）](https://blog.csdn.net/qq_21201267/article/details/101640339) |                                                              |
| [LeetCode 20. 有效的括号（栈）](https://blog.csdn.net/qq_21201267/article/details/99353358) |                                                              |
| [LeetCode 21. 合并两个有序链表（单链表）](https://blog.csdn.net/qq_21201267/article/details/100056931) |                                                              |
| [LeetCode 22. 括号生成（回溯）](https://blog.csdn.net/qq_21201267/article/details/101078481) |                                                              |
| [LeetCode 23. 合并K个排序链表（优先队列）](https://blog.csdn.net/qq_21201267/article/details/99344922) |                                                              |
| [LeetCode 24. 两两交换链表中的节点（递归+循环）](https://blog.csdn.net/qq_21201267/article/details/102597533) |                                                              |
| [LeetCode 25. K 个一组翻转链表](https://michael.blog.csdn.net/article/details/104229000) |                                                              |
| [LeetCode 26. 删除排序数组中的重复项](https://blog.csdn.net/qq_21201267/article/details/100864296) |                                                              |
| [LeetCode 27. 移除元素](https://blog.csdn.net/qq_21201267/article/details/100826960) |                                                              |
| [LeetCode 28. 实现 strStr()](https://michael.blog.csdn.net/article/details/105595931) |                                                              |
| [LeetCode 29. 两数相除（位运算）](https://blog.csdn.net/qq_21201267/article/details/102751716) |                                                              |
| [LeetCode 30. 串联所有单词的子串（字符串哈希）](https://michael.blog.csdn.net/article/details/106442789) |                                                              |
| [LeetCode 31. 下一个排列（线性扫描）](https://michael.blog.csdn.net/article/details/105371886) |                                                              |
| [LeetCode 32. 最长有效括号（栈&DP）](https://blog.csdn.net/qq_21201267/article/details/99479252) |                                                              |
| [LeetCode 33. 搜索旋转排序数组（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102415062) |                                                              |
| [LeetCode 34. 在排序数组中查找元素的第一个和最后一个位置（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102470512) |                                                              |
| [LeetCode 35. 搜索插入位置（二分查找）](https://blog.csdn.net/qq_21201267/article/details/100419471) |                                                              |
| [LeetCode 36. 有效的数独（哈希）](https://blog.csdn.net/qq_21201267/article/details/99888173) |                                                              |
| [LeetCode 37. 解数独（回溯）](https://michael.blog.csdn.net/article/details/104944124) |                                                              |
| [LeetCode 38. 报数](https://michael.blog.csdn.net/article/details/103457464) |                                                              |
| [LeetCode 39. 组合总和（回溯）](https://blog.csdn.net/qq_21201267/article/details/100678859) |                                                              |
| [LeetCode 40. 组合总和 II（排列组合 回溯）](https://blog.csdn.net/qq_21201267/article/details/101376680) |                                                              |
| [LeetCode 41. 缺失的第一个正数](https://blog.csdn.net/qq_21201267/article/details/99253353) |                                                              |
| [LeetCode 42. 接雨水（双指针、单调栈）](https://blog.csdn.net/qq_21201267/article/details/102847881) |                                                              |
| [LeetCode 43. 字符串相乘（大数乘法）](https://blog.csdn.net/qq_21201267/article/details/102825578) |                                                              |
| [LeetCode 44. 通配符匹配（DP）](https://michael.blog.csdn.net/article/details/106871306) |                                                              |
| [LeetCode 45. 跳跃游戏 II（贪心, 难）](https://blog.csdn.net/qq_21201267/article/details/100904721) |                                                              |
| [LeetCode 46. 全排列（回溯）](https://blog.csdn.net/qq_21201267/article/details/100110156) |                                                              |
| [LeetCode 47. 全排列 II（回溯+搜索剪枝）](https://blog.csdn.net/qq_21201267/article/details/100110853) |                                                              |
| [LeetCode 48. 旋转图像（一次遍历+位运算）](https://michael.blog.csdn.net/article/details/104516295) |                                                              |
| [LeetCode 49. 字母异位词分组（哈希）](https://blog.csdn.net/qq_21201267/article/details/102319498) |                                                              |
| [LeetCode 50. Pow(x, n)（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102489210) |                                                              |
| [LeetCode 51. N皇后 / 52. N皇后 II（回溯）](https://michael.blog.csdn.net/article/details/104921660) |                                                              |
| [LeetCode 53. 最大子序和（动态规划）](https://blog.csdn.net/qq_21201267/article/details/97559470) |                                                              |
| [LeetCode 55. 跳跃游戏（贪心）](https://blog.csdn.net/qq_21201267/article/details/100899698) |                                                              |
| [LeetCode 56. 合并区间（优先队列）](https://blog.csdn.net/qq_21201267/article/details/100082338) |                                                              |
| [LeetCode 57. 插入区间（一次遍历）](https://michael.blog.csdn.net/article/details/106443497) |                                                              |
| [LeetCode 58. 最后一个单词的长度](https://michael.blog.csdn.net/article/details/105596202) |                                                              |
| [LeetCode 59. 螺旋矩阵 II && LeetCode 54. 螺旋矩阵](https://blog.csdn.net/qq_21201267/article/details/100395555) |                                                              |
| [LeetCode 60. 第k个排列（回溯 & 康托展开）](https://michael.blog.csdn.net/article/details/103837916) |                                                              |
| [LeetCode 61. 旋转链表](https://blog.csdn.net/qq_21201267/article/details/100355678) |                                                              |
| [LeetCode 62. 不同路径（DP）](https://blog.csdn.net/qq_21201267/article/details/100148537) |                                                              |
| [LeetCode 63. 不同路径 II（DP）](https://michael.blog.csdn.net/article/details/102961510) |                                                              |
| [LeetCode 64. 最小路径和（DP）](https://blog.csdn.net/qq_21201267/article/details/100025545) |                                                              |
| [LeetCode 65. 有效数字（逻辑题，难）](https://blog.csdn.net/qq_21201267/article/details/104825661) |                                                              |
| [LeetCode 66. 加一](https://michael.blog.csdn.net/article/details/105596325) |                                                              |
| [LeetCode 67. 二进制求和](https://blog.csdn.net/qq_21201267/article/details/101211346) |                                                              |
| [LeetCode 68. 文本左右对齐（字符串逻辑题）](https://michael.blog.csdn.net/article/details/106723906) |                                                              |
| [LeetCode 69. x 的平方根（二分查找）](https://blog.csdn.net/qq_21201267/article/details/100585531) |                                                              |
| [LeetCode 70. 爬楼梯（动态规划）](https://blog.csdn.net/qq_21201267/article/details/98478956) |                                                              |
| [LeetCode 71. 简化路径（栈）](https://michael.blog.csdn.net/article/details/103737562) |                                                              |
| [LeetCode 72. 编辑距离（DP）](https://blog.csdn.net/qq_21201267/article/details/104314092) |                                                              |
| [LeetCode 73. 矩阵置零](https://blog.csdn.net/qq_21201267/article/details/102709330) |                                                              |
| [LeetCode 74. 搜索二维矩阵（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102713721) |                                                              |
| [LeetCode 75. 颜色分类（双指针）](https://blog.csdn.net/qq_21201267/article/details/102654682) |                                                              |
| [LeetCode 76. 最小覆盖子串（滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/102785212) |                                                              |
| [LeetCode 77. 组合（回溯）](https://blog.csdn.net/qq_21201267/article/details/101383914) |                                                              |
| [LeetCode 78. 子集（回溯）](https://blog.csdn.net/qq_21201267/article/details/100148996) |                                                              |
| [LeetCode 79. 单词搜索（回溯DFS）](https://blog.csdn.net/qq_21201267/article/details/102596927) |                                                              |
| [LeetCode 80. 删除排序数组中的重复项 II](https://blog.csdn.net/qq_21201267/article/details/102655782) |                                                              |
| [LeetCode 81. 搜索旋转排序数组 II（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102416534) |                                                              |
| [LeetCode 82. 删除排序链表中的重复元素 II（链表）](https://michael.blog.csdn.net/article/details/103340950) |                                                              |
| [LeetCode 83. 删除排序链表中的重复元素（链表）](https://michael.blog.csdn.net/article/details/103174661) |                                                              |
| [LeetCode 84. 柱状图中最大的矩形（单调递增栈）](https://michael.blog.csdn.net/article/details/106438479) |                                                              |
| [LeetCode 85. 最大矩形（DP，难）](https://michael.blog.csdn.net/article/details/104217829) |                                                              |
| [LeetCode 86. 分隔链表](https://michael.blog.csdn.net/article/details/103227124) |                                                              |
| [LeetCode 87. 扰乱字符串（记忆化递归 / DP）](https://michael.blog.csdn.net/article/details/113053927) |                                                              |
| [LeetCode 88. 合并两个有序数组](https://blog.csdn.net/qq_21201267/article/details/100056086) |                                                              |
| [LeetCode 89. 格雷编码](https://blog.csdn.net/qq_21201267/article/details/100170042) |                                                              |
| [LeetCode 90. 子集 II（回溯+剪枝）](https://blog.csdn.net/qq_21201267/article/details/100167394) |                                                              |
| [LeetCode 91. 解码方法（动态规划）](https://michael.blog.csdn.net/article/details/105889570) |                                                              |
| [LeetCode 92. 反转链表 II（双指针）](https://blog.csdn.net/qq_21201267/article/details/101646666) |                                                              |
| [LeetCode 93. 复原IP地址（回溯）](https://michael.blog.csdn.net/article/details/103673911) |                                                              |
| [LeetCode 94. 二叉树的中序遍历（中序遍历）](https://blog.csdn.net/qq_21201267/article/details/100545729) |                                                              |
| [LeetCode 95. 不同的二叉搜索树 II（递归）](https://michael.blog.csdn.net/article/details/105596395) |                                                              |
| [LeetCode 96. 不同的二叉搜索树（DP）](https://blog.csdn.net/qq_21201267/article/details/102616858) |                                                              |
| [LeetCode 97. 交错字符串（DP）](https://michael.blog.csdn.net/article/details/106879502) |                                                              |
| [LeetCode 98. 验证二叉搜索树（中序遍历）](https://blog.csdn.net/qq_21201267/article/details/99699540) |                                                              |
| [LeetCode 99. 恢复二叉搜索树（中序遍历）](https://blog.csdn.net/qq_21201267/article/details/100811472) |                                                              |
| [LeetCode 100. 相同的树（二叉树遍历）](https://blog.csdn.net/qq_21201267/article/details/100851442) |                                                              |
| [LeetCode 101. 对称二叉树（递归&循环）](https://blog.csdn.net/qq_21201267/article/details/102493073) |                                                              |
| [LeetCode 102. 二叉树的层次遍历](https://blog.csdn.net/qq_21201267/article/details/99699445) |                                                              |
| [LeetCode 103. 二叉树的锯齿形层次遍历（BFS / 双栈）](https://blog.csdn.net/qq_21201267/article/details/102712811) |                                                              |
| [LeetCode 104. 二叉树的最大深度](https://blog.csdn.net/qq_21201267/article/details/99690644) |                                                              |
| [LeetCode 105. 已知前序&中序 求二叉树](https://blog.csdn.net/qq_21201267/article/details/100752155) |                                                              |
| [LeetCode 106. 已知中序&后序 求二叉树](https://blog.csdn.net/qq_21201267/article/details/100753691) |                                                              |
| [LeetCode 107. 二叉树的层次遍历 II（队列）](https://michael.blog.csdn.net/article/details/105596834) |                                                              |
| [LeetCode 108. 将有序数组转换为二叉搜索树](https://blog.csdn.net/qq_21201267/article/details/100941767) |                                                              |
| [LeetCode 109. 有序链表转换二叉搜索树（快慢指针+递归）](https://blog.csdn.net/qq_21201267/article/details/100943280) |                                                              |
| [LeetCode 110. 平衡二叉树（二叉树高度）](https://blog.csdn.net/qq_21201267/article/details/100783394) |                                                              |
| [LeetCode 111. 二叉树的最小深度](https://blog.csdn.net/qq_21201267/article/details/99699211) |                                                              |
| [LeetCode 112. 路径总和](https://blog.csdn.net/qq_21201267/article/details/99710888) |                                                              |
| [LeetCode 113. 路径总和 II（回溯）](https://blog.csdn.net/qq_21201267/article/details/100550154) |                                                              |
| [LeetCode 114. 二叉树展开为链表（递归）](https://michael.blog.csdn.net/article/details/103215728) |                                                              |
| [LeetCode 115. 不同的子序列（DP）](https://michael.blog.csdn.net/article/details/107265347) |                                                              |
| [LeetCode 116. 填充每个节点的下一个右侧节点指针（递归&循环）](https://blog.csdn.net/qq_21201267/article/details/102508857) |                                                              |
| [LeetCode 117. 填充每个节点的下一个右侧节点指针 II（递归&循环）](https://blog.csdn.net/qq_21201267/article/details/102510857) |                                                              |
| [LeetCode 118. 杨辉三角](https://blog.csdn.net/qq_21201267/article/details/100562763) |                                                              |
| [LeetCode 119. 杨辉三角 II](https://blog.csdn.net/qq_21201267/article/details/100719218) |                                                              |
| [LeetCode 120. 三角形最小路径和](https://blog.csdn.net/qq_21201267/article/details/96380128) |                                                              |
| [LeetCode 121. 买卖股票的最佳时机](https://blog.csdn.net/qq_21201267/article/details/100026086) |                                                              |
| [LeetCode 122. 买卖股票的最佳时机 II](https://blog.csdn.net/qq_21201267/article/details/100127238) |                                                              |
| [LeetCode 123. 买卖股票的最佳时机 III（动态规划）](https://michael.blog.csdn.net/article/details/105851383) |                                                              |
| [LeetCode 124. 二叉树中的最大路径和（DFS）](https://blog.csdn.net/qq_21201267/article/details/100171375) |                                                              |
| [LeetCode 125. 验证回文串](https://michael.blog.csdn.net/article/details/105596879) |                                                              |
| [LeetCode 126. 单词接龙 II（图的BFS）](https://blog.csdn.net/qq_21201267/article/details/102808526) |                                                              |
| [LeetCode 127. 单词接龙（图的BFS/双向BFS）](https://blog.csdn.net/qq_21201267/article/details/102795986) |                                                              |
| [LeetCode 128. 最长连续序列（哈希set）](https://blog.csdn.net/qq_21201267/article/details/102769670) |                                                              |
| [LeetCode 129. 求根到叶子节点数字之和（DFS）](https://michael.blog.csdn.net/article/details/103229606) |                                                              |
| [LeetCode 130. 被围绕的区域（图的BFS/DFS）](https://blog.csdn.net/qq_21201267/article/details/102811035) |                                                              |
| [LeetCode 131. 分割回文串（回溯）](https://michael.blog.csdn.net/article/details/102979356) |                                                              |
| [LeetCode 132. 分割回文串 II（DP）](https://michael.blog.csdn.net/article/details/107290701) |                                                              |
| [LeetCode 133. 克隆图（图的BFS/DFS）](https://blog.csdn.net/qq_21201267/article/details/101568649) |                                                              |
| [LeetCode 134. 加油站（贪心）](https://blog.csdn.net/qq_21201267/article/details/102857089) |                                                              |
| [LeetCode 135. 分发糖果（DP）](https://michael.blog.csdn.net/article/details/106649583) |                                                              |
| [LeetCode 136. 只出现一次的数字（异或^）](https://blog.csdn.net/qq_21201267/article/details/100147375) |                                                              |
| [LeetCode 137. 只出现一次的数字 II（位运算）](https://blog.csdn.net/qq_21201267/article/details/101102832) |                                                              |
| [LeetCode 138. 复制带随机指针的链表（哈希 / 深拷贝）](https://blog.csdn.net/qq_21201267/article/details/101570854) |                                                              |
| [LeetCode 139. 单词拆分（DP）](https://michael.blog.csdn.net/article/details/102944920) |                                                              |
| [LeetCode 140. 单词拆分 II（DP+回溯）](https://michael.blog.csdn.net/article/details/102945974) |                                                              |
| [LeetCode 141. 环形链表](https://blog.csdn.net/qq_21201267/article/details/99296511) |                                                              |
| [LeetCode 142. 环形链表 II（链表环的检测）](https://blog.csdn.net/qq_21201267/article/details/100135575) |                                                              |
| [LeetCode 143. 重排链表（链表反转+快慢指针）](https://michael.blog.csdn.net/article/details/103341844) |                                                              |
| [LeetCode 144. 二叉树的前序遍历（前序遍历）](https://blog.csdn.net/qq_21201267/article/details/100546064) |                                                              |
| [LeetCode 145. 二叉树的后序遍历（后序遍历&总结）](https://blog.csdn.net/qq_21201267/article/details/100546489) |                                                              |
| [LeetCode 146. LRU缓存机制（哈希链表）](https://blog.csdn.net/qq_21201267/article/details/100178189) |                                                              |
| [LeetCode 147. 对链表进行插入排序（链表）](https://michael.blog.csdn.net/article/details/103346625) |                                                              |
| [LeetCode 148. 排序链表（归并排序）](https://blog.csdn.net/qq_21201267/article/details/101313065) |                                                              |
| [LeetCode 149. 直线上最多的点数](https://blog.csdn.net/qq_21201267/article/details/102674893) |                                                              |
| [LeetCode 150. 逆波兰表达式求值（栈）](https://blog.csdn.net/qq_21201267/article/details/99495282) |                                                              |
| [LeetCode 151. 翻转字符串里的单词（栈）](https://blog.csdn.net/qq_21201267/article/details/99663417) |                                                              |
| [LeetCode 152. 乘积最大子序列（DP）](https://blog.csdn.net/qq_21201267/article/details/100006586) |                                                              |
| [LeetCode 153. 寻找旋转排序数组中的最小值（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102423232) |                                                              |
| [LeetCode 154. 寻找旋转排序数组中的最小值 II（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102491605) |                                                              |
| [LeetCode 155. 最小栈](https://blog.csdn.net/qq_21201267/article/details/100188954) |                                                              |
| [LeetCode 156. 上下翻转二叉树（DFS）*](https://blog.csdn.net/qq_21201267/article/details/107112729) |                                                              |
| [LeetCode 157. 用 Read4 读取 N 个字符](https://blog.csdn.net/qq_21201267/article/details/107097728) |                                                              |
| [LeetCode 158. 用 Read4 读取 N 个字符 II](https://michael.blog.csdn.net/article/details/107404980) |                                                              |
| [LeetCode 159. 至多包含两个不同字符的最长子串（滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/107179327) |                                                              |
| [LeetCode 160. 相交链表](https://blog.csdn.net/qq_21201267/article/details/100168364) |                                                              |
| [LeetCode 161. 相隔为 1 的编辑距离（DP/遍历）](https://blog.csdn.net/qq_21201267/article/details/107179471) |                                                              |
| [LeetCode 162. 寻找峰值（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102418806) |                                                              |
| [LeetCode 163. 缺失的区间](https://blog.csdn.net/qq_21201267/article/details/107186322) |                                                              |
| [LeetCode 164. 最大间距（桶排序）](https://michael.blog.csdn.net/article/details/107325529) |                                                              |
| [LeetCode 165. 比较版本号](https://michael.blog.csdn.net/article/details/103674332) |                                                              |
| [LeetCode 166. 分数到小数（小数除法）](https://blog.csdn.net/qq_21201267/article/details/102757990) |                                                              |
| [LeetCode 167. 两数之和 II - 输入有序数组（双指针）](https://michael.blog.csdn.net/article/details/105596937) |                                                              |
| [LeetCode 168. Excel表列名称](https://michael.blog.csdn.net/article/details/105597232) |                                                              |
| [LeetCode 169. 求众数](https://blog.csdn.net/qq_21201267/article/details/99249031) |                                                              |
| [LeetCode 170. 两数之和 III - 数据结构设计（哈希map）](https://blog.csdn.net/qq_21201267/article/details/107091848) |                                                              |
| [LeetCode 171. Excel表列序号（26进制转10进制）](https://blog.csdn.net/qq_21201267/article/details/100998473) |                                                              |
| [LeetCode 172. 阶乘后的零（5的因子）](https://michael.blog.csdn.net/article/details/105127249) |                                                              |
| [LeetCode 173. 二叉搜索树迭代器（中序遍历）](https://blog.csdn.net/qq_21201267/article/details/100549417) |                                                              |
| [LeetCode 174. 地下城游戏（DP）](https://michael.blog.csdn.net/article/details/107302622) |                                                              |
| [LeetCode 179. 最大数（自定义谓词函数（Lambda表达式）排序）](https://blog.csdn.net/qq_21201267/article/details/102827816) |                                                              |
| [LeetCode 186. 翻转字符串里的单词 II](https://blog.csdn.net/qq_21201267/article/details/107115195) |                                                              |
| [LeetCode 187. 重复的DNA序列（哈希/位运算）](https://michael.blog.csdn.net/article/details/106093316) |                                                              |
| [LeetCode 188. 买卖股票的最佳时机 IV（动态规划）](https://michael.blog.csdn.net/article/details/105855583) |                                                              |
| [LeetCode 189. 旋转数组（环形替换）](https://blog.csdn.net/qq_21201267/article/details/102303036) |                                                              |
| [LeetCode 190. 颠倒二进制位（位运算）](https://michael.blog.csdn.net/article/details/105597369) |                                                              |
| [LeetCode 191. 位1的个数（位运算）](https://michael.blog.csdn.net/article/details/104289467) |                                                              |
| [LeetCode 198. 打家劫舍（DP）](https://blog.csdn.net/qq_21201267/article/details/102688966) |                                                              |
| [LeetCode 199. 二叉树的右视图（DFS & 按层queue）](https://blog.csdn.net/qq_21201267/article/details/100801826) |                                                              |
| [LeetCode 200. 岛屿数量（图的遍历）](https://blog.csdn.net/qq_21201267/article/details/99775387) |                                                              |
| [LeetCode 201. 数字范围按位与（位运算）](https://michael.blog.csdn.net/article/details/106083586) |                                                              |
| [LeetCode 202. 快乐数（快慢指针）](https://blog.csdn.net/qq_21201267/article/details/101003351) |                                                              |
| [LeetCode 203. 移除链表元素](https://michael.blog.csdn.net/article/details/105597582) |                                                              |
| [LeetCode 204. 计数质数（质数的倍数不是质数）](https://blog.csdn.net/qq_21201267/article/details/102693327) |                                                              |
| [LeetCode 205. 同构字符串（哈希map）](https://michael.blog.csdn.net/article/details/105597645) |                                                              |
| [LeetCode 206. 反转链表](https://blog.csdn.net/qq_21201267/article/details/100171825) |                                                              |
| [LeetCode 207. 课程表（拓扑排序）](https://michael.blog.csdn.net/article/details/106117214) |                                                              |
| [LeetCode 208. 实现 Trie (前缀树)](https://blog.csdn.net/qq_21201267/article/details/102558647) |                                                              |
| [LeetCode 209. 长度最小的子数组（滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/102266837) |                                                              |
| [LeetCode 210. 课程表 II（拓扑排序）](https://michael.blog.csdn.net/article/details/106119461) |                                                              |
| [LeetCode 211. 添加与搜索单词 - 数据结构设计（Trie树）](https://blog.csdn.net/qq_21201267/article/details/102576715) |                                                              |
| [LeetCode 212. 单词搜索 II（Trie树+DFS）](https://blog.csdn.net/qq_21201267/article/details/102596672) |                                                              |
| [LeetCode 213. 打家劫舍 II（DP）](https://blog.csdn.net/qq_21201267/article/details/102690431) |                                                              |
| [LeetCode 214. 最短回文串（字符串哈希）](https://michael.blog.csdn.net/article/details/108301067) |                                                              |
| [LeetCode 215. 数组中的第K个最大元素（快速排序）](https://blog.csdn.net/qq_21201267/article/details/102558253) |                                                              |
| [LeetCode 216. 组合总和 III（排列组合 回溯）](https://blog.csdn.net/qq_21201267/article/details/101369537) |                                                              |
| [LeetCode 217. 存在重复元素（哈希）](https://blog.csdn.net/qq_21201267/article/details/100587491) |                                                              |
| [LeetCode 218. 天际线问题（multiset优先队列）*](https://michael.blog.csdn.net/article/details/107368401) |                                                              |
| [LeetCode 219. 存在重复元素 II（哈希）](https://blog.csdn.net/qq_21201267/article/details/100587915) |                                                              |
| [LeetCode 220. 存在重复元素 III（lower_bound）](https://blog.csdn.net/qq_21201267/article/details/100601000) |                                                              |
| [LeetCode 221. 最大正方形（DP）](https://blog.csdn.net/qq_21201267/article/details/100027699) |                                                              |
| [LeetCode 222. 完全二叉树的节点个数（二分查找）](https://michael.blog.csdn.net/article/details/103115934) |                                                              |
| [LeetCode 223. 矩形面积](https://michael.blog.csdn.net/article/details/106095806) |                                                              |
| [LeetCode 224. 基本计算器（栈）](https://michael.blog.csdn.net/article/details/106949773) |                                                              |
| [LeetCode 225. 用队列实现栈](https://blog.csdn.net/qq_21201267/article/details/100718103) |                                                              |
| [LeetCode 226. 翻转二叉树（DFS & BFS）](https://blog.csdn.net/qq_21201267/article/details/99675950) |                                                              |
| [LeetCode 227. 基本计算器 II（栈）](https://blog.csdn.net/qq_21201267/article/details/102778292) |                                                              |
| [LeetCode 228. 汇总区间](https://michael.blog.csdn.net/article/details/106096697) |                                                              |
| [LeetCode 229. 求众数 II（摩尔投票）](https://michael.blog.csdn.net/article/details/103737859) |                                                              |
| [LeetCode 230. 二叉搜索树中第K小的元素（中序遍历）](https://blog.csdn.net/qq_21201267/article/details/100530272) |                                                              |
| [LeetCode 231. 2的幂 && LeetCode 338. 比特位计数（2进制1的个数）](https://blog.csdn.net/qq_21201267/article/details/100084705) |                                                              |
| [LeetCode 232. 用栈实现队列（双栈法->队列）](https://blog.csdn.net/qq_21201267/article/details/100800928) |                                                              |
| [LeetCode 233. 数字 1 的个数（找规律）](https://michael.blog.csdn.net/article/details/104911201) |                                                              |
| [LeetCode 234. 回文链表（快慢指针+链表反转）](https://blog.csdn.net/qq_21201267/article/details/101678435) |                                                              |
| [LeetCode 235. 二叉搜索树的最近公共祖先](https://blog.csdn.net/qq_21201267/article/details/100868602) |                                                              |
| [LeetCode 236. 二叉树的最近公共祖先](https://blog.csdn.net/qq_21201267/article/details/100869188) |                                                              |
| [LeetCode 237. 删除链表中的节点](https://blog.csdn.net/qq_21201267/article/details/100171651) |                                                              |
| [LeetCode 238. 除自身以外数组的乘积](https://blog.csdn.net/qq_21201267/article/details/100530702) |                                                              |
| [LeetCode 239. 滑动窗口最大值（双端队列）](https://blog.csdn.net/qq_21201267/article/details/99613437) |                                                              |
| [LeetCode 240. 搜索二维矩阵 II（二分查找 && 分治）](https://blog.csdn.net/qq_21201267/article/details/102734391) |                                                              |
| [LeetCode 241. 为运算表达式设计优先级（动态规划）](https://michael.blog.csdn.net/article/details/105731156) |                                                              |
| [LeetCode 242. 有效的字母异位词](https://michael.blog.csdn.net/article/details/105597880) |                                                              |
| [LeetCode 243. 最短单词距离](https://blog.csdn.net/qq_21201267/article/details/107096025) |                                                              |
| [LeetCode 244. 最短单词距离 II（哈希map+set二分查找）](https://blog.csdn.net/qq_21201267/article/details/107182627) |                                                              |
| [LeetCode 245. 最短单词距离 III](https://blog.csdn.net/qq_21201267/article/details/107158455) |                                                              |
| [LeetCode 246. 中心对称数（哈希）](https://blog.csdn.net/qq_21201267/article/details/107100817) |                                                              |
| [LeetCode 247. 中心对称数 II（DP）](https://blog.csdn.net/qq_21201267/article/details/107187553) |                                                              |
| [LeetCode 248. 中心对称数 III（DFS/BFS）](https://michael.blog.csdn.net/article/details/107771370) |                                                              |
| [LeetCode 249. 移位字符串分组（哈希）](https://blog.csdn.net/qq_21201267/article/details/107091606) |                                                              |
| [LeetCode 250. 统计同值子树（递归）](https://blog.csdn.net/qq_21201267/article/details/107129161) |                                                              |
| [LeetCode 251. 展开二维向量](https://blog.csdn.net/qq_21201267/article/details/107188646) |                                                              |
| [LeetCode 252. 会议室（排序）](https://blog.csdn.net/qq_21201267/article/details/107097396) |                                                              |
| [LeetCode 253. 会议室 II（贪心+优先队列）](https://blog.csdn.net/qq_21201267/article/details/107189220) |                                                              |
| [LeetCode 254. 因子的组合（回溯）*](https://blog.csdn.net/qq_21201267/article/details/107191639) |                                                              |
| [LeetCode 255. 验证前序遍历序列二叉搜索树（单调栈）*](https://blog.csdn.net/qq_21201267/article/details/107192282) |                                                              |
| [LeetCode 256. 粉刷房子（DP）](https://blog.csdn.net/qq_21201267/article/details/107097331) |                                                              |
| [LeetCode 257. 二叉树的所有路径（DFS）](https://blog.csdn.net/qq_21201267/article/details/100565918) |                                                              |
| [LeetCode 258. 各位相加](https://michael.blog.csdn.net/article/details/105598080) |                                                              |
| [LeetCode 259. 较小的三数之和（固定一点，内层双指针）](https://blog.csdn.net/qq_21201267/article/details/107193646) |                                                              |
| [LeetCode 260. 只出现一次的数字 III（位运算）](https://blog.csdn.net/qq_21201267/article/details/101104783) |                                                              |
| [LeetCode 261. 以图判树（全部连通+边数=V-1）](https://blog.csdn.net/qq_21201267/article/details/107149024) |                                                              |
| [LeetCode 263. 丑数 && 264. 丑数 II（DP）](https://michael.blog.csdn.net/article/details/103738537) |                                                              |
| [LeetCode 265. 粉刷房子 II（DP）](https://blog.csdn.net/qq_21201267/article/details/107230412) |                                                              |
| [LeetCode 266. 回文排列（计数）](https://blog.csdn.net/qq_21201267/article/details/107096561) |                                                              |
| [LeetCode 267. 回文排列 II（回溯）](https://blog.csdn.net/qq_21201267/article/details/107233716) |                                                              |
| [LeetCode 268. 缺失数字](https://blog.csdn.net/qq_21201267/article/details/100146249) |                                                              |
| [LeetCode 269. 火星词典（拓扑排序）](https://michael.blog.csdn.net/article/details/107346218) |                                                              |
| [LeetCode 270. 最接近的二叉搜索树值](https://blog.csdn.net/qq_21201267/article/details/107090656) |                                                              |
| [LeetCode 271. 字符串的编码与解码（4位16进制字符+字符串）](https://michael.blog.csdn.net/article/details/107571561) |                                                              |
| [LeetCode 272. 最接近的二叉搜索树值 II（栈+优先队列）](https://blog.csdn.net/qq_21201267/article/details/107232667) |                                                              |
| [LeetCode 273. 整数转换英文表示](https://michael.blog.csdn.net/article/details/103093410) |                                                              |
| [LeetCode 274. H指数（排序，哈希）](https://michael.blog.csdn.net/article/details/103691047) |                                                              |
| [LeetCode 275. H指数 II（二分查找）](https://michael.blog.csdn.net/article/details/103691399) |                                                              |
| [LeetCode 276. 栅栏涂色（DP）](https://blog.csdn.net/qq_21201267/article/details/107103497) |                                                              |
| [LeetCode 277. 搜寻名人（思维题）](https://michael.blog.csdn.net/article/details/107369072) |                                                              |
| [LeetCode 278. 第一个错误的版本（二分查找）](https://michael.blog.csdn.net/article/details/105598387) |                                                              |
| [LeetCode 279. 完全平方数（DP）](https://blog.csdn.net/qq_21201267/article/details/101487022) |                                                              |
| [LeetCode 280. 摆动排序](https://michael.blog.csdn.net/article/details/107380850) |                                                              |
| [LeetCode 281. 锯齿迭代器（map+vector）](https://blog.csdn.net/qq_21201267/article/details/107115010) |                                                              |
| [LeetCode 283. 移动零](https://blog.csdn.net/qq_21201267/article/details/100832987) |                                                              |
| [LeetCode 284. 顶端迭代器](https://michael.blog.csdn.net/article/details/105598512) |                                                              |
| [LeetCode 285. 二叉搜索树中的顺序后继（中序遍历）](https://blog.csdn.net/qq_21201267/article/details/107131934) |                                                              |
| [LeetCode 286. 墙与门（BFS）](https://blog.csdn.net/qq_21201267/article/details/107062537) |                                                              |
| [LeetCode 287. 寻找重复数（BitMap）](https://blog.csdn.net/qq_21201267/article/details/100135972) |                                                              |
| [LeetCode 288. 单词的唯一缩写（哈希）](https://blog.csdn.net/qq_21201267/article/details/107092387) |                                                              |
| [LeetCode 289. 生命游戏（位运算）](https://blog.csdn.net/qq_21201267/article/details/102787583) |                                                              |
| [LeetCode 290. 单词规律（哈希）](https://michael.blog.csdn.net/article/details/103053073) |                                                              |
| [LeetCode 291. 单词规律 II（回溯）](https://michael.blog.csdn.net/article/details/107973244) |                                                              |
| [LeetCode 292. Nim 游戏](https://blog.csdn.net/qq_21201267/article/details/100178975) |                                                              |
| [LeetCode 293. 翻转游戏](https://blog.csdn.net/qq_21201267/article/details/107094697) |                                                              |
| [LeetCode 294. 翻转游戏 II（记忆化递归）](https://michael.blog.csdn.net/article/details/107571038) |                                                              |
| [LeetCode 295. 数据流的中位数（大小堆）](https://blog.csdn.net/qq_21201267/article/details/102865997) |                                                              |
| [LeetCode 296. 最佳的碰头地点（坐标独立+中位数的地方最近）](https://michael.blog.csdn.net/article/details/107498938) |                                                              |
| [LeetCode 297. 二叉树的序列化与反序列化（前序遍历&层序遍历）](https://blog.csdn.net/qq_21201267/article/details/102513143) |                                                              |
| [LeetCode 298. 二叉树最长连续序列（自顶向下）](https://blog.csdn.net/qq_21201267/article/details/107172224) |                                                              |
| [LeetCode 299. 猜数字游戏](https://michael.blog.csdn.net/article/details/105244199) |                                                              |
| [LeetCode 300. 最长上升子序列](https://blog.csdn.net/qq_21201267/article/details/97308533) |                                                              |
| [LeetCode 301. 删除无效的括号（回溯）](https://michael.blog.csdn.net/article/details/107347465) |                                                              |
| [LeetCode 302. 包含全部黑色像素的最小矩形（BFS）](https://michael.blog.csdn.net/article/details/107520781) |                                                              |
| [LeetCode 303. 区域和检索 - 数组不可变（前缀和）](https://michael.blog.csdn.net/article/details/105629224) |                                                              |
| [LeetCode 304. 二维区域和检索 - 矩阵不可变（DP）](https://blog.csdn.net/qq_21201267/article/details/101219854) |                                                              |
| [LeetCode 305. 岛屿数量 II（并查集）](https://blog.csdn.net/qq_21201267/article/details/107226324) |                                                              |
| [LeetCode 306. 累加数（暴力回溯）](https://michael.blog.csdn.net/article/details/103813396) |                                                              |
| [LeetCode 307. 区域和检索 - 数组可修改（树状数组）](https://michael.blog.csdn.net/article/details/105632022) |                                                              |
| [LeetCode 308. 二维区域和检索 - 可变（前缀和）](https://michael.blog.csdn.net/article/details/107417676) |                                                              |
| [LeetCode 309. 最佳买卖股票时机含冷冻期（动态规划）](https://michael.blog.csdn.net/article/details/105858950) |                                                              |
| [LeetCode 310. 最小高度树（图 聪明的BFS，从外向内包围）](https://michael.blog.csdn.net/article/details/103244463) |                                                              |
| [LeetCode 311. 稀疏矩阵的乘法](https://blog.csdn.net/qq_21201267/article/details/107113508) |                                                              |
| [LeetCode 312. 戳气球（DP，难）](https://blog.csdn.net/qq_21201267/article/details/100838793) |                                                              |
| [LeetCode 313. 超级丑数（动态规划）](https://michael.blog.csdn.net/article/details/105932017) |                                                              |
| [LeetCode 314. 二叉树的垂直遍历（BFS/DFS）](https://michael.blog.csdn.net/article/details/107825446) |                                                              |
| [LeetCode 315. 计算右侧小于当前元素的个数（二叉查找树&二分查找&归并排序逆序数总结）](https://blog.csdn.net/qq_21201267/article/details/102876496) |                                                              |
| [LeetCode 316. 去除重复字母（单调栈）](https://michael.blog.csdn.net/article/details/109538681) |                                                              |
| [LeetCode 317. 离建筑物最近的距离（逆向BFS）*](https://michael.blog.csdn.net/article/details/107923146) |                                                              |
| [LeetCode 318. 最大单词长度乘积（位运算）](https://michael.blog.csdn.net/article/details/103231137) |                                                              |
| [LeetCode 319. 灯泡开关（找规律）](https://michael.blog.csdn.net/article/details/103607028) |                                                              |
| [LeetCode 320. 列举单词的全部缩写（回溯/位运算）](https://michael.blog.csdn.net/article/details/107859696) |                                                              |
| [LeetCode 321. 拼接最大数（单调栈）*](https://michael.blog.csdn.net/article/details/110519913) |                                                              |
| [LeetCode 322. 零钱兑换（DP）](https://blog.csdn.net/qq_21201267/article/details/99894804) |                                                              |
| [LeetCode 323. 无向图中连通分量的数目（并查集）](https://blog.csdn.net/qq_21201267/article/details/107123017) |                                                              |
| [LeetCode 324. 摆动排序 II](https://blog.csdn.net/qq_21201267/article/details/102871040) |                                                              |
| [LeetCode 325. 和等于 k 的最长子数组长度（哈希表记录第一次出现的状态）](https://michael.blog.csdn.net/article/details/107350185) |                                                              |
| [LeetCode 326. 3的幂](https://michael.blog.csdn.net/article/details/105644651) |                                                              |
| [LeetCode 327. 区间和的个数（multiset二分查找/归并排序）](https://michael.blog.csdn.net/article/details/105636619) |                                                              |
| [LeetCode 328. 奇偶链表（双指针）](https://blog.csdn.net/qq_21201267/article/details/101649623) |                                                              |
| [LeetCode 329. 矩阵中的最长递增路径（记忆化递归）](https://michael.blog.csdn.net/article/details/107592908) |                                                              |
| [LeetCode 330. 按要求补齐数组（贪心）](https://michael.blog.csdn.net/article/details/111880950) |                                                              |
| [LeetCode 331. 验证二叉树的前序序列化](https://michael.blog.csdn.net/article/details/105679759) |                                                              |
| [LeetCode 332. 重新安排行程（欧拉路径）](https://michael.blog.csdn.net/article/details/106124337) |                                                              |
| [LeetCode 333. 最大 BST 子树（递归）*](https://blog.csdn.net/qq_21201267/article/details/107148640) |                                                              |
| [LeetCode 334. 递增的三元子序列](https://blog.csdn.net/qq_21201267/article/details/101275950) |                                                              |
| [LeetCode 336. 回文对（哈希map）](https://michael.blog.csdn.net/article/details/107834330) |                                                              |
| [LeetCode 337. 打家劫舍 III（记忆化+递归）](https://blog.csdn.net/qq_21201267/article/details/102691125) |                                                              |
| [LeetCode 339. 嵌套列表权重和（DFS）](https://blog.csdn.net/qq_21201267/article/details/107093614) |                                                              |
| [LeetCode 340. 至多包含 K 个不同字符的最长子串（滑动窗口）](https://michael.blog.csdn.net/article/details/107399576) |                                                              |
| [LeetCode 341. 扁平化嵌套列表迭代器（双栈）](https://blog.csdn.net/qq_21201267/article/details/102869784) |                                                              |
| [LeetCode 342. 4的幂（位运算）](https://michael.blog.csdn.net/article/details/103095417) |                                                              |
| [LeetCode 343. 整数拆分（DP）](https://michael.blog.csdn.net/article/details/102942661) |                                                              |
| [LeetCode 344. 反转字符串](https://blog.csdn.net/qq_21201267/article/details/100585634) |                                                              |
| [LeetCode 345. 反转字符串中的元音字母](https://michael.blog.csdn.net/article/details/105644920) |                                                              |
| [LeetCode 346. 数据流中的移动平均值（队列）](https://blog.csdn.net/qq_21201267/article/details/107090493) |                                                              |
| [LeetCode 347. 前 K 个高频元素（哈希/优先队列）](https://blog.csdn.net/qq_21201267/article/details/102338389) |                                                              |
| [LeetCode 348. 判定井字棋胜负（计数）](https://michael.blog.csdn.net/article/details/107418123) |                                                              |
| [LeetCode 349. 两个数组的交集（哈希）](https://blog.csdn.net/qq_21201267/article/details/100945076) |                                                              |
| [LeetCode 350. 两个数组的交集 II（哈希）](https://blog.csdn.net/qq_21201267/article/details/100995174) |                                                              |
| [LeetCode 351. 安卓系统手势解锁（回溯）](https://michael.blog.csdn.net/article/details/107738912) |                                                              |
| [LeetCode 352. 将数据流变为多个不相交区间（map二分查找）](https://michael.blog.csdn.net/article/details/113062808) |                                                              |
| [LeetCode 353. 贪吃蛇（deque+set）](https://michael.blog.csdn.net/article/details/107886222) |                                                              |
| [LeetCode 354. 俄罗斯套娃信封问题（最长上升子序 DP/二分查找）](https://michael.blog.csdn.net/article/details/105370146) |                                                              |
| [LeetCode 355. 设计推特（哈希map+set）](https://michael.blog.csdn.net/article/details/105480197) |                                                              |
| [LeetCode 356. 直线镜像](https://michael.blog.csdn.net/article/details/107528027) |                                                              |
| [LeetCode 357. 计算各个位数不同的数字个数（DP）](https://michael.blog.csdn.net/article/details/103844098) |                                                              |
| [LeetCode 358. K 距离间隔重排字符串（贪心+优先队列）](https://michael.blog.csdn.net/article/details/107987014) |                                                              |
| [LeetCode 359. 日志速率限制器（哈希map）](https://blog.csdn.net/qq_21201267/article/details/107091236) |                                                              |
| [LeetCode 360. 有序转化数组（抛物线对称轴）](https://michael.blog.csdn.net/article/details/107499297) |                                                              |
| [LeetCode 361. 轰炸敌人（前缀和DP）](https://michael.blog.csdn.net/article/details/107527864) |                                                              |
| [LeetCode 362. 敲击计数器（map）](https://blog.csdn.net/qq_21201267/article/details/107118573) |                                                              |
| [LeetCode 363. 矩形区域不超过 K 的最大数值和（DP+set二分查找）](https://michael.blog.csdn.net/article/details/106447907) |                                                              |
| [LeetCode 364. 加权嵌套序列和 II（重复叠加）](https://michael.blog.csdn.net/article/details/107586036) |                                                              |
| [LeetCode 365. 水壶问题（最大公约数）](https://michael.blog.csdn.net/article/details/102980961) |                                                              |
| [LeetCode 366. 寻找二叉树的叶子节点（上下翻转二叉树+BFS）](https://blog.csdn.net/qq_21201267/article/details/107156510) |                                                              |
| [LeetCode 367. 有效的完全平方数（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102489562) |                                                              |
| [LeetCode 368. 最大整除子集（DP）](https://michael.blog.csdn.net/article/details/106816075) |                                                              |
| [LeetCode 369. 给单链表加一（递归）](https://blog.csdn.net/qq_21201267/article/details/107117484) |                                                              |
| [LeetCode 370. 区间加法（差分思想）](https://blog.csdn.net/qq_21201267/article/details/107125689) |                                                              |
| [LeetCode 371. 两整数之和（位运算）](https://michael.blog.csdn.net/article/details/105645358) |                                                              |
| [LeetCode 372. 超级次方（快速幂）](https://michael.blog.csdn.net/article/details/106189267) |                                                              |
| [LeetCode 373. 查找和最小的K对数字（自定义优先队列BFS）](https://blog.csdn.net/qq_21201267/article/details/106199628) |                                                              |
| [LeetCode 374. 猜数字大小（二分查找）](https://michael.blog.csdn.net/article/details/105647930) |                                                              |
| [LeetCode 375. 猜数字大小 II（DP）](https://michael.blog.csdn.net/article/details/108015839) |                                                              |
| [LeetCode 376. 摆动序列（贪心 & 动态规划）](https://michael.blog.csdn.net/article/details/103848407) |                                                              |
| [LeetCode 377. 组合总和 Ⅳ（DP）](https://blog.csdn.net/qq_21201267/article/details/101388583) |                                                              |
| [LeetCode 378. 有序矩阵中第K小的元素（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102866438) |                                                              |
| [LeetCode 379. 电话目录管理系统（哈希set）](https://blog.csdn.net/qq_21201267/article/details/107128113) |                                                              |
| [LeetCode 380. 常数时间插入、删除和获取随机元素（哈希+vector）](https://blog.csdn.net/qq_21201267/article/details/102407866) |                                                              |
| [LeetCode 381. O(1) 时间插入、删除和获取随机元素 - 允许重复（vector + 哈希）](https://michael.blog.csdn.net/article/details/109391076) |                                                              |
| [LeetCode 382. 链表随机节点（概率）](https://michael.blog.csdn.net/article/details/103228024) |                                                              |
| [LeetCode 383. 赎金信](https://michael.blog.csdn.net/article/details/105664299) |                                                              |
| [LeetCode 384. 打乱数组（rand）](https://blog.csdn.net/qq_21201267/article/details/102692973) |                                                              |
| [LeetCode 385. 迷你语法分析器（栈）](https://michael.blog.csdn.net/article/details/115016272) |                                                              |
| [LeetCode 386. 字典序排数（DFS&循环）](https://michael.blog.csdn.net/article/details/103218150) |                                                              |
| [LeetCode 387. 字符串中的第一个唯一字符](https://michael.blog.csdn.net/article/details/105664799) |                                                              |
| [LeetCode 388. 文件的最长绝对路径（不用栈，前缀和）](https://michael.blog.csdn.net/article/details/106210795) |                                                              |
| [LeetCode 389. 找不同（位运算）](https://blog.csdn.net/qq_21201267/article/details/101165255) |                                                              |
| [LeetCode 390. 消除游戏（类似约瑟夫环，找映射规律）](https://michael.blog.csdn.net/article/details/106376201) |                                                              |
| [LeetCode 391. 完美矩形（set检查顶点+面积检查）](https://blog.csdn.net/qq_21201267/article/details/106922771) |                                                              |
| [LeetCode 392. 判断子序列（双指针&二分查找）](https://michael.blog.csdn.net/article/details/103206471) |                                                              |
| [LeetCode 393. UTF-8 编码验证（位运算）](https://blog.csdn.net/qq_21201267/article/details/106197435) |                                                              |
| [LeetCode 394. 字符串解码（栈）](https://blog.csdn.net/qq_21201267/article/details/101607649) |                                                              |
| [LeetCode 395. 至少有K个重复字符的最长子串（分治）](https://michael.blog.csdn.net/article/details/106299647) |                                                              |
| [LeetCode 396. 旋转函数（数学）](https://michael.blog.csdn.net/article/details/103931570) |                                                              |
| [LeetCode 397. 整数替换（递归 & 贪心）](https://michael.blog.csdn.net/article/details/103838630) |                                                              |
| [LeetCode 398. 随机数索引（概率）](https://michael.blog.csdn.net/article/details/103382205) |                                                              |
| [LeetCode 399. 除法求值（图的DFS搜索）](https://michael.blog.csdn.net/article/details/106353698) |                                                              |
| [LeetCode 400. 第N个数字（数学）](https://michael.blog.csdn.net/article/details/103571864) |                                                              |
| [LeetCode 401. 二进制手表](https://michael.blog.csdn.net/article/details/103134538) |                                                              |
| [LeetCode 402. 移掉K位数字（贪心，单调栈）](https://michael.blog.csdn.net/article/details/103555712) |                                                              |
| [LeetCode 403. 青蛙过河（DP）](https://michael.blog.csdn.net/article/details/102969736) |                                                              |
| [LeetCode 404. 左叶子之和（递归）](https://michael.blog.csdn.net/article/details/103041375) |                                                              |
| [LeetCode 405. 数字转换为十六进制数](https://michael.blog.csdn.net/article/details/105665100) |                                                              |
| [LeetCode 406. 根据身高重建队列（排序）](https://michael.blog.csdn.net/article/details/105749075) |                                                              |
| [LeetCode 408. 有效单词缩写](https://blog.csdn.net/qq_21201267/article/details/107108142) |                                                              |
| [LeetCode 409. 最长回文串（计数）](https://michael.blog.csdn.net/article/details/104959667) |                                                              |
| [LeetCode 410. 分割数组的最大值（极小极大化 二分查找 / DP）](https://michael.blog.csdn.net/article/details/107573654) |                                                              |
| [LeetCode 412. Fizz Buzz](https://michael.blog.csdn.net/article/details/105665256) |                                                              |
| [LeetCode 413. 等差数列划分（DP）](https://blog.csdn.net/qq_21201267/article/details/100831735) |                                                              |
| [LeetCode 414. 第三大的数](https://blog.csdn.net/qq_21201267/article/details/102789337) |                                                              |
| [LeetCode 415. 字符串相加（大数加法）](https://blog.csdn.net/qq_21201267/article/details/102821516) |                                                              |
| [LeetCode 416. 分割等和子集（动态规划）](https://michael.blog.csdn.net/article/details/106216416) |                                                              |
| [LeetCode 417. 太平洋大西洋水流问题（BFS/DFS）](https://michael.blog.csdn.net/article/details/106208344) |                                                              |
| [LeetCode 418. 屏幕可显示句子的数量（DP）*](https://michael.blog.csdn.net/article/details/107916144) |                                                              |
| [LeetCode 419. 甲板上的战舰](https://michael.blog.csdn.net/article/details/105665399) |                                                              |
| [LeetCode 421. 数组中两个数的最大异或值（Trie树）](https://blog.csdn.net/qq_21201267/article/details/102577639) |                                                              |
| [LeetCode 422. 有效的单词方块](https://blog.csdn.net/qq_21201267/article/details/107104807) |                                                              |
| [LeetCode 423. 从英文中重建数字（找规律）](https://michael.blog.csdn.net/article/details/103517719) |                                                              |
| [LeetCode 424. 替换后的最长重复字符（滑动窗口）](https://michael.blog.csdn.net/article/details/106213574) |                                                              |
| [LeetCode 425. 单词方块（Trie树+DFS）](https://michael.blog.csdn.net/article/details/107623109) |                                                              |
| [LeetCode 426. 将二叉搜索树转化为排序的双向链表（BST中序循环遍历）](https://blog.csdn.net/qq_21201267/article/details/107129959) |                                                              |
| [LeetCode 427. 建立四叉树（递归）](https://michael.blog.csdn.net/article/details/103038783) |                                                              |
| [LeetCode 428. 序列化和反序列化 N 叉树（DFS）](https://michael.blog.csdn.net/article/details/107349431) |                                                              |
| [LeetCode 429. N叉树的层序遍历（queue）](https://blog.csdn.net/qq_21201267/article/details/100714179) |                                                              |
| [LeetCode 430. 扁平化多级双向链表（DFS）](https://blog.csdn.net/qq_21201267/article/details/101723144) |                                                              |
| [LeetCode 431. 将 N 叉树编码为二叉树（递归/层序）](https://michael.blog.csdn.net/article/details/107946182) |                                                              |
| [LeetCode 432. 全 O(1) 的数据结构（设计题）*](https://michael.blog.csdn.net/article/details/107373267) |                                                              |
| [LeetCode 433. 最小基因变化（广度优先搜索）](https://michael.blog.csdn.net/article/details/106156216) |                                                              |
| [LeetCode 434. 字符串中的单词数](https://michael.blog.csdn.net/article/details/105665544) |                                                              |
| [LeetCode 435. 无重叠区间（贪心/动态规划）](https://michael.blog.csdn.net/article/details/106154262) |                                                              |
| [LeetCode 436. 寻找右区间（二分查找）](https://michael.blog.csdn.net/article/details/106156914) |                                                              |
| [LeetCode 437. 路径总和 III（双重递归）](https://blog.csdn.net/qq_21201267/article/details/100906264) |                                                              |
| [LeetCode 438. 找到字符串中所有字母异位词（滑动窗口）](https://michael.blog.csdn.net/article/details/106149447) |                                                              |
| [LeetCode 439. 三元表达式解析器](https://michael.blog.csdn.net/article/details/107772478) |                                                              |
| [LeetCode 441. 排列硬币（数学解方程）](https://michael.blog.csdn.net/article/details/105665692) |                                                              |
| [LeetCode 442. 数组中重复的数据](https://blog.csdn.net/qq_21201267/article/details/100798552) |                                                              |
| [LeetCode 443. 压缩字符串（双指针）](https://michael.blog.csdn.net/article/details/103051059) |                                                              |
| [LeetCode 444. 序列重建（拓扑排序）](https://michael.blog.csdn.net/article/details/107884725) |                                                              |
| [LeetCode 445. 两数相加 II（链表大数加法）](https://michael.blog.csdn.net/article/details/103500675) |                                                              |
| [LeetCode 447. 回旋镖的数量（哈希map+组合数）](https://michael.blog.csdn.net/article/details/105689424) |                                                              |
| [LeetCode 448. 找到所有数组中消失的数字](https://blog.csdn.net/qq_21201267/article/details/101475950) |                                                              |
| [LeetCode 450. 删除二叉搜索树中的节点](https://blog.csdn.net/qq_21201267/article/details/102540298) |                                                              |
| [LeetCode 451. 根据字符出现频率排序（map+优先队列）](https://blog.csdn.net/qq_21201267/article/details/102671877) |                                                              |
| [LeetCode 452. 用最少数量的箭打破气球（贪心）](https://michael.blog.csdn.net/article/details/106257682) |                                                              |
| [LeetCode 453. 最小移动次数使数组元素相等（数学）](https://michael.blog.csdn.net/article/details/103128867) |                                                              |
| [LeetCode 454. 四数相加 II（哈希）](https://blog.csdn.net/qq_21201267/article/details/102336145) |                                                              |
| [LeetCode 455. 分发饼干（贪心）](https://michael.blog.csdn.net/article/details/103073602) |                                                              |
| [LeetCode 456. 132模式（逆序遍历+单调栈）](https://michael.blog.csdn.net/article/details/105688840) |                                                              |
| [LeetCode 457. 环形数组循环（暴力+快慢指针）](https://michael.blog.csdn.net/article/details/106152551) |                                                              |
| [LeetCode 459. 重复的子字符串（数学）](https://michael.blog.csdn.net/article/details/103208056) |                                                              |
| [LeetCode 460. LFU缓存（哈希双链表）](https://michael.blog.csdn.net/article/details/105336389) |                                                              |
| [LeetCode 461. 汉明距离（异或^ 与&）](https://blog.csdn.net/qq_21201267/article/details/100632232) |                                                              |
| [LeetCode 462. 最少移动次数使数组元素相等 II（数学）](https://michael.blog.csdn.net/article/details/103356799) |                                                              |
| [LeetCode 463. 岛屿的周长](https://blog.csdn.net/qq_21201267/article/details/101063020) |                                                              |
| [LeetCode 464. 我能赢吗（状态压缩+记忆化递归）](https://michael.blog.csdn.net/article/details/112104426) |                                                              |
| [LeetCode 466. 统计重复个数（循环节）](https://michael.blog.csdn.net/article/details/105622283) |                                                              |
| [LeetCode 467. 环绕字符串中唯一的子字符串（思维转换）](https://michael.blog.csdn.net/article/details/106150226) |                                                              |
| [LeetCode 468. 验证IP地址](https://michael.blog.csdn.net/article/details/103672706) |                                                              |
| [LeetCode 469. 凸多边形（向量叉积）](https://michael.blog.csdn.net/article/details/107866949) |                                                              |
| [LeetCode 470. 用 Rand7() 实现 Rand10()（随机概率）](https://michael.blog.csdn.net/article/details/103560871) |                                                              |
| [LeetCode 473. 火柴拼正方形（回溯）](https://michael.blog.csdn.net/article/details/108000169) |                                                              |
| [LeetCode 474. 一和零（动态规划）](https://michael.blog.csdn.net/article/details/106256106) |                                                              |
| [LeetCode 475. 供暖器（双指针&二分查找）](https://blog.csdn.net/qq_21201267/article/details/102989014) |                                                              |
| [LeetCode 476. 数字的补数（移位 异或^）](https://blog.csdn.net/qq_21201267/article/details/100938652) |                                                              |
| [LeetCode 477. 汉明距离总和（位运算）](https://blog.csdn.net/qq_21201267/article/details/103410908) |                                                              |
| [LeetCode 478. 在圆内随机生成点（概率）](https://michael.blog.csdn.net/article/details/103341534) |                                                              |
| [LeetCode 480. 滑动窗口中位数（大小堆升级版+set实现）](https://michael.blog.csdn.net/article/details/106962644) |                                                              |
| [LeetCode 481. 神奇字符串（找规律）](https://michael.blog.csdn.net/article/details/103606978) |                                                              |
| [LeetCode 482. 密钥格式化](https://blog.csdn.net/qq_21201267/article/details/102888974) |                                                              |
| [LeetCode 483. 最小好进制（二分查找）](https://michael.blog.csdn.net/article/details/118036047) |                                                              |
| [LeetCode 484. 寻找排列（找规律+贪心）](https://blog.csdn.net/qq_21201267/article/details/107168148) |                                                              |
| [LeetCode 485. 最大连续1的个数](https://blog.csdn.net/qq_21201267/article/details/100855102) |                                                              |
| [LeetCode 486. 预测赢家（博弈DP）](https://michael.blog.csdn.net/article/details/108337865) |                                                              |
| [LeetCode 487. 最大连续1的个数 II（滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/107194857) |                                                              |
| [LeetCode 489. 扫地机器人（DFS）](https://michael.blog.csdn.net/article/details/107581006) |                                                              |
| [LeetCode 490. 迷宫（BFS/DFS）](https://blog.csdn.net/qq_21201267/article/details/107215680) |                                                              |
| [LeetCode 491. 递增子序列（回溯+判重剪枝）](https://michael.blog.csdn.net/article/details/106157529) |                                                              |
| [LeetCode 492. 构造矩形](https://michael.blog.csdn.net/article/details/105689887) |                                                              |
| [LeetCode 493. 翻转对（归并排序）](https://blog.csdn.net/qq_21201267/article/details/101236925) |                                                              |
| [LeetCode 494. 目标和（DFS+DP）](https://blog.csdn.net/qq_21201267/article/details/101556163) |                                                              |
| [LeetCode 495. 提莫攻击](https://michael.blog.csdn.net/article/details/103838976) |                                                              |
| [LeetCode 496. 下一个更大元素 I（哈希）](https://blog.csdn.net/qq_21201267/article/details/101391976) |                                                              |
| [LeetCode 497. 非重叠矩形中的随机点（前缀和+二分查找）](https://michael.blog.csdn.net/article/details/113002128) |                                                              |
| [LeetCode 498. 对角线遍历](https://blog.csdn.net/qq_21201267/article/details/102264166) |                                                              |
| [LeetCode 500. 键盘行](https://blog.csdn.net/qq_21201267/article/details/100674362) |                                                              |
| [LeetCode 501. 二叉搜索树中的众数（中序遍历）](https://michael.blog.csdn.net/article/details/102997543) |                                                              |
| [LeetCode 502. IPO（优先队列）](https://michael.blog.csdn.net/article/details/120186608) |                                                              |
| [LeetCode 503. 下一个更大元素 II（栈）](https://blog.csdn.net/qq_21201267/article/details/101394230) |                                                              |
| [LeetCode 504. 七进制数（进制转换）](https://blog.csdn.net/qq_21201267/article/details/102904814) |                                                              |
| [LeetCode 505. 迷宫 II（BFS / Dijkstra 最短路径）](https://blog.csdn.net/qq_21201267/article/details/107222887) |                                                              |
| [LeetCode 506. 相对名次（map）](https://michael.blog.csdn.net/article/details/105690403) |                                                              |
| [LeetCode 507. 完美数](https://michael.blog.csdn.net/article/details/105690940) |                                                              |
| [LeetCode 508. 出现次数最多的子树元素和（递归）](https://michael.blog.csdn.net/article/details/105715277) |                                                              |
| [LeetCode 509. 斐波那契数](https://michael.blog.csdn.net/article/details/104272616) |                                                              |
| [LeetCode 510. 二叉搜索树中的中序后继 II（查找右子树或者祖父节点）](https://blog.csdn.net/qq_21201267/article/details/107132442) |                                                              |
| [LeetCode 513. 找树左下角的值（按层遍历 queue）](https://blog.csdn.net/qq_21201267/article/details/100677982) |                                                              |
| [LeetCode 514. 自由之路（记忆化递归 / DP）](https://michael.blog.csdn.net/article/details/109633004) |                                                              |
| [LeetCode 515. 在每个树行中找最大值（层序遍历）](https://michael.blog.csdn.net/article/details/103341623) |                                                              |
| [LeetCode 516. 最长回文子序列（动态规划）](https://michael.blog.csdn.net/article/details/106161439) |                                                              |
| [LeetCode 518. 零钱兑换 II（动态规划）](https://michael.blog.csdn.net/article/details/106049588) |                                                              |
| [LeetCode 519. 随机翻转矩阵（哈希）](https://michael.blog.csdn.net/article/details/106380151) |                                                              |
| [LeetCode 520. 检测大写字母](https://michael.blog.csdn.net/article/details/105715687) |                                                              |
| [LeetCode 521. 最长特殊序列 Ⅰ](https://michael.blog.csdn.net/article/details/105716003) |                                                              |
| [LeetCode 522. 最长特殊序列 II](https://blog.csdn.net/qq_21201267/article/details/101036485) |                                                              |
| [LeetCode 523. 连续的子数组和（求余 哈希）](https://blog.csdn.net/qq_21201267/article/details/102253351) |                                                              |
| [LeetCode 524. 通过删除字母匹配到字典里最长单词（双指针）](https://michael.blog.csdn.net/article/details/106685806) |                                                              |
| [LeetCode 525. 连续数组（前缀和+哈希）](https://michael.blog.csdn.net/article/details/106157791) |                                                              |
| [LeetCode 526. 优美的排列（回溯）](https://michael.blog.csdn.net/article/details/103383968) |                                                              |
| [LeetCode 527. 单词缩写（Trie树）](https://michael.blog.csdn.net/article/details/107951276) |                                                              |
| [LeetCode 528. 按权重随机选择（前缀和+二分查找）](https://michael.blog.csdn.net/article/details/113004631) |                                                              |
| [LeetCode 529. 扫雷游戏（广度优先搜索BFS/深度优先搜索DFS）](https://michael.blog.csdn.net/article/details/105960312) |                                                              |
| [LeetCode 530. 二叉搜索树的最小绝对差（中序遍历）](https://michael.blog.csdn.net/article/details/102964835) |                                                              |
| [LeetCode 531. 孤独像素 I](https://blog.csdn.net/qq_21201267/article/details/107126367) |                                                              |
| [LeetCode 532. 数组中的K-diff数对](https://michael.blog.csdn.net/article/details/105717133) |                                                              |
| [LeetCode 533. 孤独像素 II](https://blog.csdn.net/qq_21201267/article/details/107127000) |                                                              |
| [LeetCode 535. TinyURL 的加密与解密（哈希）](https://blog.csdn.net/qq_21201267/article/details/100565409) |                                                              |
| [LeetCode 536. 从字符串生成二叉树（递归）](https://michael.blog.csdn.net/article/details/107537043) |                                                              |
| [LeetCode 537. 复数乘法](https://michael.blog.csdn.net/article/details/102981551) |                                                              |
| [LeetCode 538. 把二叉搜索树转换为累加树（逆中序 根右左）](https://blog.csdn.net/qq_21201267/article/details/100826415) |                                                              |
| [LeetCode 539. 最小时间差（哈希）](https://michael.blog.csdn.net/article/details/103498922) |                                                              |
| [LeetCode 540. 有序数组中的单一元素（位运算&二分查找）](https://michael.blog.csdn.net/article/details/103377708) |                                                              |
| [LeetCode 541. 反转字符串 II](https://michael.blog.csdn.net/article/details/103041243) |                                                              |
| [LeetCode 542. 01 矩阵（BFS && DP）](https://blog.csdn.net/qq_21201267/article/details/101618467) |                                                              |
| [LeetCode 543. 二叉树的直径（DFS）](https://blog.csdn.net/qq_21201267/article/details/102818983) |                                                              |
| [LeetCode 544. 输出比赛匹配对（NBA季后赛对阵图）](https://blog.csdn.net/qq_21201267/article/details/107123966) |                                                              |
| [LeetCode 545. 二叉树的边界（前序+后序）*](https://blog.csdn.net/qq_21201267/article/details/107148491) |                                                              |
| [LeetCode 546. 移除盒子（DP）*](https://michael.blog.csdn.net/article/details/108030579) |                                                              |
| [LeetCode 547. 朋友圈（图的遍历BFS & DFS）](https://blog.csdn.net/qq_21201267/article/details/100813067) |                                                              |
| [LeetCode 548. 将数组分割成和相等的子数组（哈希set）](https://michael.blog.csdn.net/article/details/107866197) |                                                              |
| [LeetCode 549. 二叉树中最长的连续序列（树上DP）](https://michael.blog.csdn.net/article/details/107576568) |                                                              |
| [LeetCode 551. 学生出勤记录 I](https://michael.blog.csdn.net/article/details/105717322) |                                                              |
| [LeetCode 552. 学生出勤记录 II（动态规划）](https://michael.blog.csdn.net/article/details/112250211) |                                                              |
| [LeetCode 553. 最优除法（数学）](https://michael.blog.csdn.net/article/details/103515354) |                                                              |
| [LeetCode 554. 砖墙（map计数）](https://michael.blog.csdn.net/article/details/106590186) |                                                              |
| [LeetCode 555. 分割连接字符串](https://michael.blog.csdn.net/article/details/107824427) |                                                              |
| [LeetCode 556. 下一个更大元素 III](https://michael.blog.csdn.net/article/details/103940133) |                                                              |
| [LeetCode 557. 反转字符串中的单词 III（栈）](https://blog.csdn.net/qq_21201267/article/details/100436745) |                                                              |
| [LeetCode 558. 四叉树交集（递归）](https://michael.blog.csdn.net/article/details/103098556) |                                                              |
| [LeetCode 559. N叉树的最大深度](https://blog.csdn.net/qq_21201267/article/details/100943751) |                                                              |
| [LeetCode 560. 和为K的子数组（前缀和差分）](https://michael.blog.csdn.net/article/details/105657944) |                                                              |
| [LeetCode 561. 数组拆分 I](https://blog.csdn.net/qq_21201267/article/details/100940866) |                                                              |
| [LeetCode 562. 矩阵中最长的连续1线段（DP）](https://blog.csdn.net/qq_21201267/article/details/107205044) |                                                              |
| [LeetCode 563. 二叉树的坡度（DFS）](https://blog.csdn.net/qq_21201267/article/details/102904432) |                                                              |
| [LeetCode 565. 数组嵌套](https://michael.blog.csdn.net/article/details/106832333) |                                                              |
| [LeetCode 566. 重塑矩阵](https://michael.blog.csdn.net/article/details/105717990) |                                                              |
| [LeetCode 567. 字符串的排列（滑动窗口）](https://michael.blog.csdn.net/article/details/106387977) |                                                              |
| [LeetCode 568. 最大休假天数（DP）](https://michael.blog.csdn.net/article/details/107920933) |                                                              |
| [LeetCode 572. 另一个树的子树（二叉树迭代器）](https://michael.blog.csdn.net/article/details/103094146) |                                                              |
| [LeetCode 573. 松鼠模拟（数学）*](https://blog.csdn.net/qq_21201267/article/details/107144624) |                                                              |
| [LeetCode 575. 分糖果（set集合去重）](https://blog.csdn.net/qq_21201267/article/details/101039768) |                                                              |
| [LeetCode 576. 出界的路径数（动态规划）](https://michael.blog.csdn.net/article/details/108729988) |                                                              |
| [LeetCode 581. 最短无序连续子数组（排序&单调栈）](https://michael.blog.csdn.net/article/details/103208650) |                                                              |
| [LeetCode 582. 杀死进程（图的遍历）](https://michael.blog.csdn.net/article/details/107880885) |                                                              |
| [LeetCode 583. 两个字符串的删除操作（动态规划）](https://michael.blog.csdn.net/article/details/106009461) |                                                              |
| [LeetCode 587. 安装栅栏 / LintCode 1152. 安装栅栏（凸包检测：排序+叉积正负判断+正反扫描+去重）](https://michael.blog.csdn.net/article/details/113039017) |                                                              |
| [LeetCode 589. N叉树的前序遍历（前序遍历）](https://blog.csdn.net/qq_21201267/article/details/100747568) |                                                              |
| [LeetCode 590. N叉树的后序遍历（后序遍历）](https://blog.csdn.net/qq_21201267/article/details/100749955) |                                                              |
| [LeetCode 592. 分数加减运算（字符串+最大公约数）](https://michael.blog.csdn.net/article/details/106730621) |                                                              |
| [LeetCode 593. 有效的正方形（数学）](https://michael.blog.csdn.net/article/details/106926403) |                                                              |
| [LeetCode 594. 最长和谐子序列（map）](https://michael.blog.csdn.net/article/details/102924359) |                                                              |
| [LeetCode 598. 范围求和 II](https://michael.blog.csdn.net/article/details/105719055) |                                                              |
| [LeetCode 599. 两个列表的最小索引总和（哈希map）](https://michael.blog.csdn.net/article/details/105719230) |                                                              |
| [LeetCode 604. 迭代压缩字符串](https://blog.csdn.net/qq_21201267/article/details/107106968) |                                                              |
| [LeetCode 605. 种花问题](https://blog.csdn.net/qq_21201267/article/details/102904001) |                                                              |
| [LeetCode 606. 根据二叉树创建字符串（递归）](https://michael.blog.csdn.net/article/details/103021068) |                                                              |
| [LeetCode 609. 在系统中查找重复文件（哈希）](https://michael.blog.csdn.net/article/details/106932074) |                                                              |
| [LeetCode 611. 有效三角形的个数（双指针）](https://michael.blog.csdn.net/article/details/103649865) |                                                              |
| [LeetCode 616. 给字符串添加加粗标签（Trie树）](https://michael.blog.csdn.net/article/details/107399624) |                                                              |
| [LeetCode 617. 合并二叉树](https://blog.csdn.net/qq_21201267/article/details/100569367) |                                                              |
| [LeetCode 621. 任务调度器（贪心）](https://blog.csdn.net/qq_21201267/article/details/102760180) |                                                              |
| [LeetCode 622. 设计循环队列](https://michael.blog.csdn.net/article/details/105719813) |                                                              |
| [LeetCode 623. 在二叉树中增加一行（BFS/DFS）](https://michael.blog.csdn.net/article/details/103649398) |                                                              |
| [LeetCode 624. 数组列表中的最大距离](https://blog.csdn.net/qq_21201267/article/details/107105100) |                                                              |
| [LeetCode 625. 最小因式分解（贪心）](https://michael.blog.csdn.net/article/details/107880373) |                                                              |
| [LeetCode 628. 三个数的最大乘积](https://michael.blog.csdn.net/article/details/103172263) |                                                              |
| [LeetCode 629. K个逆序对数组（DP）](https://blog.csdn.net/qq_21201267/article/details/102886587) |                                                              |
| [LeetCode 632. 最小区间（排序+滑动窗口）](https://michael.blog.csdn.net/article/details/107727739) |                                                              |
| [LeetCode 633. 平方数之和（双指针）](https://michael.blog.csdn.net/article/details/105720281) |                                                              |
| [LeetCode 634. 寻找数组的错位排列（DP）](https://michael.blog.csdn.net/article/details/107577515) |                                                              |
| [LeetCode 635. 设计日志存储系统（map）](https://michael.blog.csdn.net/article/details/107497677) |                                                              |
| [LeetCode 636. 函数的独占时间（栈）](https://michael.blog.csdn.net/article/details/108766683) |                                                              |
| [LeetCode 637. 二叉树的层平均值（层次遍历queue）](https://blog.csdn.net/qq_21201267/article/details/100717726) |                                                              |
| [LeetCode 638. 大礼包（无限背包DP）](https://michael.blog.csdn.net/article/details/106290676) |                                                              |
| [LeetCode 640. 求解方程（字符串）](https://michael.blog.csdn.net/article/details/106435972) |                                                              |
| [LeetCode 641. 设计循环双端队列](https://blog.csdn.net/qq_21201267/article/details/99496486) |                                                              |
| [LeetCode 642. 设计搜索自动补全系统（Trie树）](https://michael.blog.csdn.net/article/details/107624559) |                                                              |
| [LeetCode 643. 子数组最大平均数 I](https://michael.blog.csdn.net/article/details/105720427) |                                                              |
| [LeetCode 644. 最大平均子段和 II（二分查找）*](https://michael.blog.csdn.net/article/details/107947499) |                                                              |
| [LeetCode 645. 错误的集合](https://blog.csdn.net/qq_21201267/article/details/100148227) |                                                              |
| [LeetCode 646. 最长数对链（区间 贪心）](https://blog.csdn.net/qq_21201267/article/details/101239559) |                                                              |
| [LeetCode 647. 回文子串（DP）](https://michael.blog.csdn.net/article/details/105576327) |                                                              |
| [LeetCode 648. 单词替换（Trie树）](https://blog.csdn.net/qq_21201267/article/details/102574082) |                                                              |
| [LeetCode 649. Dota2 参议院（循环队列）](https://michael.blog.csdn.net/article/details/111055016) |                                                              |
| [LeetCode 650. 只有两个键的键盘（DP）](https://michael.blog.csdn.net/article/details/103657566) |                                                              |
| [LeetCode 651. 4键键盘（DP，Ctrl+CV）](https://blog.csdn.net/qq_21201267/article/details/107170933) |                                                              |
| [LeetCode 652. 寻找重复的子树（DFS）](https://blog.csdn.net/qq_21201267/article/details/101284456) |                                                              |
| [LeetCode 653. 两数之和 IV - 输入 BST（二叉搜索树迭代器&双指针）](https://michael.blog.csdn.net/article/details/103019314) |                                                              |
| [LeetCode 654. 最大二叉树（递归）](https://blog.csdn.net/qq_21201267/article/details/100586036) |                                                              |
| [LeetCode 655. 输出二叉树（二叉树高度&二叉树遍历）](https://michael.blog.csdn.net/article/details/103099751) |                                                              |
| [LeetCode 656. 金币路径（DP）](https://michael.blog.csdn.net/article/details/107968343) |                                                              |
| [LeetCode 657. 机器人能否返回原点](https://blog.csdn.net/qq_21201267/article/details/100632672) |                                                              |
| [LeetCode 658. 找到 K 个最接近的元素（二分查找）](https://blog.csdn.net/qq_21201267/article/details/100697216) |                                                              |
| [LeetCode 659. 分割数组为连续子序列（哈希）](https://michael.blog.csdn.net/article/details/108059351) |                                                              |
| [LeetCode 660. 移除 9（9进制）](https://michael.blog.csdn.net/article/details/107529684) |                                                              |
| [LeetCode 661. 图片平滑器](https://michael.blog.csdn.net/article/details/105720542) |                                                              |
| [LeetCode 662. 二叉树最大宽度（递归）](https://michael.blog.csdn.net/article/details/106249487) |                                                              |
| [LeetCode 663. 均匀树划分（树形DP）](https://blog.csdn.net/qq_21201267/article/details/107148685) |                                                              |
| [LeetCode 664. 奇怪的打印机（区间DP）](https://michael.blog.csdn.net/article/details/117266977) |                                                              |
| [LeetCode 665. 非递减数列（双指针）](https://blog.csdn.net/qq_21201267/article/details/102810529) |                                                              |
| [LeetCode 666. 路径和 IV（树的遍历）](https://blog.csdn.net/qq_21201267/article/details/107120811) |                                                              |
| [LeetCode 667. 优美的排列 II（找规律）](https://blog.csdn.net/qq_21201267/article/details/103411623) |                                                              |
| [LeetCode 668. 乘法表中第k小的数（二分查找）](https://michael.blog.csdn.net/article/details/112058480) |                                                              |
| [LeetCode 669. 修剪二叉搜索树](https://blog.csdn.net/qq_21201267/article/details/100716292) |                                                              |
| [LeetCode 670. 最大交换](https://michael.blog.csdn.net/article/details/106271125) |                                                              |
| [LeetCode 671. 二叉树中第二小的节点](https://blog.csdn.net/qq_21201267/article/details/100550016) |                                                              |
| [LeetCode 672. 灯泡开关 Ⅱ（枚举）](https://blog.csdn.net/qq_21201267/article/details/105811367) |                                                              |
| [LeetCode 673. 最长递增子序列的个数（DP）](https://michael.blog.csdn.net/article/details/106677852) |                                                              |
| [LeetCode 674. 最长连续递增序列](https://blog.csdn.net/qq_21201267/article/details/98262871) |                                                              |
| [LeetCode 676. 实现一个魔法字典（哈希）](https://michael.blog.csdn.net/article/details/103511709) |                                                              |
| [LeetCode 677. 键值映射（Trie树）](https://blog.csdn.net/qq_21201267/article/details/102559253) |                                                              |
| [LeetCode 678. 有效的括号字符串（栈）](https://michael.blog.csdn.net/article/details/103865442) |                                                              |
| [LeetCode 679. 24 点游戏（回溯）](https://michael.blog.csdn.net/article/details/108164000) |                                                              |
| [LeetCode 680. 验证回文字符串 Ⅱ](https://michael.blog.csdn.net/article/details/105739399) |                                                              |
| [LeetCode 681. 最近时刻](https://michael.blog.csdn.net/article/details/107393074) |                                                              |
| [LeetCode 682. 棒球比赛](https://michael.blog.csdn.net/article/details/105739564) |                                                              |
| [LeetCode 683. K 个空花盆（set/滑动窗口）](https://michael.blog.csdn.net/article/details/107390522) |                                                              |
| [LeetCode 684. 冗余连接（并查集）](https://michael.blog.csdn.net/article/details/106396495) |                                                              |
| [LeetCode 685. 冗余连接 II（并查集）](https://michael.blog.csdn.net/article/details/106410823) |                                                              |
| [LeetCode 686. 重复叠加字符串匹配](https://michael.blog.csdn.net/article/details/103193202) |                                                              |
| [LeetCode 687. 最长同值路径（二叉树，递归）](https://michael.blog.csdn.net/article/details/103191442) |                                                              |
| [LeetCode 688. “马”在棋盘上的概率（DP）](https://michael.blog.csdn.net/article/details/108913560) |                                                              |
| [LeetCode 690. 员工的重要性（图的DFS&BFS）](https://michael.blog.csdn.net/article/details/103153141) |                                                              |
| [LeetCode 692. 前K个高频单词（优先队列）](https://michael.blog.csdn.net/article/details/106008947) |                                                              |
| [LeetCode 693. 交替位二进制数（位运算）](https://blog.csdn.net/qq_21201267/article/details/101096121) |                                                              |
| [LeetCode 694. 不同岛屿的数量（BFS/DFS+set）](https://michael.blog.csdn.net/article/details/107419494) |                                                              |
| [LeetCode 695. 岛屿的最大面积（图的BFS/DFS）](https://michael.blog.csdn.net/article/details/103036801) |                                                              |
| [LeetCode 696. 计数二进制子串](https://michael.blog.csdn.net/article/details/103074623) |                                                              |
| [LeetCode 697. 数组的度](https://michael.blog.csdn.net/article/details/105739714) |                                                              |
| [LeetCode 698. 划分为k个相等的子集（回溯）](https://michael.blog.csdn.net/article/details/109649315) |                                                              |
| [LeetCode 700. 二叉搜索树中的搜索](https://blog.csdn.net/qq_21201267/article/details/100906799) |                                                              |
| [LeetCode 701. 二叉搜索树中的插入操作（二叉查找树/插入）](https://blog.csdn.net/qq_21201267/article/details/100696071) |                                                              |
| [LeetCode 702. 搜索长度未知的有序数组（二分查找）](https://blog.csdn.net/qq_21201267/article/details/107091044) |                                                              |
| [LeetCode 703. 数据流中的第K大元素（优先队列）](https://michael.blog.csdn.net/article/details/105739876) |                                                              |
| [LeetCode 704. 二分查找](https://blog.csdn.net/qq_21201267/article/details/100715644) |                                                              |
| [LeetCode 705. 设计哈希集合](https://michael.blog.csdn.net/article/details/105740141) |                                                              |
| [LeetCode 706. 设计哈希映射](https://michael.blog.csdn.net/article/details/105740273) |                                                              |
| [LeetCode 707. 设计链表（List）](https://blog.csdn.net/qq_21201267/article/details/101638997) |                                                              |
| [LeetCode 708. 循环有序列表的插入](https://michael.blog.csdn.net/article/details/107883084) |                                                              |
| [LeetCode 709. 转换成小写字母](https://blog.csdn.net/qq_21201267/article/details/100907747) |                                                              |
| [LeetCode 712. 两个字符串的最小ASCII删除和（DP，类似编辑距离）](https://michael.blog.csdn.net/article/details/105757207) |                                                              |
| [LeetCode 713. 乘积小于K的子数组（滑动窗口）](https://michael.blog.csdn.net/article/details/106733134) |                                                              |
| [LeetCode 714. 买卖股票的最佳时机含手续费（DP）](https://michael.blog.csdn.net/article/details/103381475) |                                                              |
| [LeetCode 716. 最大栈（双栈 / list+map）](https://blog.csdn.net/qq_21201267/article/details/107102162) |                                                              |
| [LeetCode 717. 1比特与2比特字符](https://michael.blog.csdn.net/article/details/105740439) |                                                              |
| [LeetCode 718. 最长重复子数组（DP）](https://michael.blog.csdn.net/article/details/106584030) |                                                              |
| [LeetCode 720. 词典中最长的单词（Trie树）](https://michael.blog.csdn.net/article/details/103077004) |                                                              |
| [LeetCode 721. 账户合并（并查集）](https://michael.blog.csdn.net/article/details/108704420) |                                                              |
| [LeetCode 722. 删除注释（逻辑题）](https://michael.blog.csdn.net/article/details/103917615) |                                                              |
| [LeetCode 723. 粉碎糖果（模拟）](https://michael.blog.csdn.net/article/details/107899231) |                                                              |
| [LeetCode 724. 寻找数组的中心索引](https://michael.blog.csdn.net/article/details/105740610) |                                                              |
| [LeetCode 725. 分隔链表](https://michael.blog.csdn.net/article/details/103883892) |                                                              |
| [LeetCode 727. 最小窗口子序列（滑动窗口）](https://michael.blog.csdn.net/article/details/107994370) |                                                              |
| [LeetCode 728. 自除数](https://blog.csdn.net/qq_21201267/article/details/100907175) |                                                              |
| [LeetCode 729. 我的日程安排表 I（set 二分查找）](https://michael.blog.csdn.net/article/details/108843058) |                                                              |
| [LeetCode 731. 我的日程安排表 II（set二分查找 / 差分思想）](https://michael.blog.csdn.net/article/details/108847657) |                                                              |
| [LeetCode 732. 我的日程安排表 III（差分思想）](https://michael.blog.csdn.net/article/details/108889442) |                                                              |
| [LeetCode 733. 图像渲染（DFS/BFS）](https://blog.csdn.net/qq_21201267/article/details/101611121) |                                                              |
| [LeetCode 734. 句子相似性（哈希）](https://blog.csdn.net/qq_21201267/article/details/107098723) |                                                              |
| [LeetCode 735. 行星碰撞（栈）](https://michael.blog.csdn.net/article/details/103794858) |                                                              |
| [LeetCode 737. 句子相似性 II（并查集）](https://michael.blog.csdn.net/article/details/107881526) |                                                              |
| [LeetCode 738. 单调递增的数字（贪心）](https://michael.blog.csdn.net/article/details/103564931) |                                                              |
| [LeetCode 739. 每日温度（单调栈）](https://blog.csdn.net/qq_21201267/article/details/101479101) |                                                              |
| [LeetCode 740. 删除与获得点数（排序+动态规划）](https://michael.blog.csdn.net/article/details/108662137) |                                                              |
| [LeetCode 742. 二叉树最近的叶节点（建立父节点信息+BFS）](https://blog.csdn.net/qq_21201267/article/details/107212921) |                                                              |
| [LeetCode 743. 网络延迟时间（最短路径）](https://michael.blog.csdn.net/article/details/106686629) |                                                              |
| [LeetCode 744. 寻找比目标字母大的最小字母（二分查找）](https://blog.csdn.net/qq_21201267/article/details/102489881) |                                                              |
| [LeetCode 746. 使用最小花费爬楼梯（DP）](https://blog.csdn.net/qq_21201267/article/details/102905456) |                                                              |
| [LeetCode 747. 至少是其他数字两倍的最大数](https://michael.blog.csdn.net/article/details/105740878) |                                                              |
| [LeetCode 748. 最短完整词](https://michael.blog.csdn.net/article/details/105798998) |                                                              |
| [LeetCode 750. 角矩形的数量（DP）](https://blog.csdn.net/qq_21201267/article/details/107233886) |                                                              |
| [LeetCode 751. IP 到 CIDR（贪心）](https://michael.blog.csdn.net/article/details/107416095) |                                                              |
| [LeetCode 752. 打开转盘锁（图的BFS最短路径）](https://blog.csdn.net/qq_21201267/article/details/101485240) |                                                              |
| [LeetCode 753. 破解保险箱（DFS）](https://michael.blog.csdn.net/article/details/112689705) |                                                              |
| [LeetCode 754. 到达终点数字（数学推理）](https://blog.csdn.net/qq_21201267/article/details/102888341) |                                                              |
| [LeetCode 755. 倒水（模拟）](https://michael.blog.csdn.net/article/details/107883940) |                                                              |
| [LeetCode 756. 金字塔转换矩阵（回溯）](https://michael.blog.csdn.net/article/details/109537003) |                                                              |
| [LeetCode 758. 字符串中的加粗单词（Trie树）](https://blog.csdn.net/qq_21201267/article/details/107100343) |                                                              |
| [LeetCode 759. 员工空闲时间（排序）](https://michael.blog.csdn.net/article/details/107967098) |                                                              |
| [LeetCode 760. 找出变位映射（哈希）](https://blog.csdn.net/qq_21201267/article/details/107092979) |                                                              |
| [LeetCode 762. 二进制表示中质数个计算置位](https://blog.csdn.net/qq_21201267/article/details/101039460) |                                                              |
| [LeetCode 763. 划分字母区间](https://blog.csdn.net/qq_21201267/article/details/100677335) |                                                              |
| [LeetCode 764. 最大加号标志（DP）](https://michael.blog.csdn.net/article/details/109341035) |                                                              |
| [LeetCode 765. 情侣牵手（贪心）](https://blog.csdn.net/qq_21201267/article/details/100839491) |                                                              |
| [LeetCode 766. 托普利茨矩阵](https://michael.blog.csdn.net/article/details/105798793) |                                                              |
| [LeetCode 767. 重构字符串（堆）](https://michael.blog.csdn.net/article/details/108841568) |                                                              |
| [LeetCode 769. 最多能完成排序的块](https://michael.blog.csdn.net/article/details/105795329) |                                                              |
| [LeetCode 771. 宝石与石头（哈希）](https://blog.csdn.net/qq_21201267/article/details/100563578) |                                                              |
| [LeetCode 773. 滑动谜题（BFS 地图状态转换的最短距离）](https://michael.blog.csdn.net/article/details/104118648) |                                                              |
| [LeetCode 774. 最小化去加油站的最大距离（极小极大化 二分查找）](https://michael.blog.csdn.net/article/details/107947144) |                                                              |
| [LeetCode 775. 全局倒置与局部倒置（归并排序/二分查找/一次遍历）](https://michael.blog.csdn.net/article/details/108779463) |                                                              |
| [LeetCode 776. 拆分二叉搜索树（DFS）*](https://michael.blog.csdn.net/article/details/107520331) |                                                              |
| [LeetCode 777. 在LR字符串中交换相邻字符（双指针）](https://michael.blog.csdn.net/article/details/103866042) |                                                              |
| [LeetCode 778. 水位上升的泳池中游泳（二分查找+dfs）](https://michael.blog.csdn.net/article/details/108959211) |                                                              |
| [LeetCode 779. 第K个语法符号（找规律）](https://michael.blog.csdn.net/article/details/105762582) |                                                              |
| [LeetCode 781. 森林中的兔子（哈希+贪心）](https://michael.blog.csdn.net/article/details/112988015) |                                                              |
| [LeetCode 783. 二叉搜索树结点最小距离（中序遍历）](https://blog.csdn.net/qq_21201267/article/details/100784063) |                                                              |
| [LeetCode 784. 字母大小写全排列（位运算&回溯）](https://blog.csdn.net/qq_21201267/article/details/101179369) |                                                              |
| [LeetCode 785. 判断二分图（染色法）](https://michael.blog.csdn.net/article/details/107374120) |                                                              |
| [LeetCode 787. K 站中转内最便宜的航班（Dijkstra最短路径 + 优先队列）](https://michael.blog.csdn.net/article/details/109094212) |                                                              |
| [LeetCode 788. 旋转数字](https://michael.blog.csdn.net/article/details/105775643) |                                                              |
| [LeetCode 789. 逃脱阻碍者（曼哈顿距离）](https://michael.blog.csdn.net/article/details/106827480) |                                                              |
| [LeetCode 790. 多米诺和托米诺平铺（动态规划）](https://michael.blog.csdn.net/article/details/112343026) |                                                              |
| [LeetCode 791. 自定义字符串排序（map）](https://michael.blog.csdn.net/article/details/103219936) |                                                              |
| [LeetCode 792. 匹配子序列的单词数（二分查找）](https://michael.blog.csdn.net/article/details/112331864) |                                                              |
| [LeetCode 793. 阶乘函数后K个零（二分查找）](https://michael.blog.csdn.net/article/details/106347098) |                                                              |
| [LeetCode 794. 有效的井字游戏（分类讨论）](https://michael.blog.csdn.net/article/details/109136501) |                                                              |
| [LeetCode 795. 区间子数组个数](https://michael.blog.csdn.net/article/details/109657808) |                                                              |
| [LeetCode 796. 旋转字符串](https://michael.blog.csdn.net/article/details/105775449) |                                                              |
| [LeetCode 797. 所有可能的路径（DFS）](https://blog.csdn.net/qq_21201267/article/details/101574194) |                                                              |
| [LeetCode 799. 香槟塔（DP动态规划）](https://michael.blog.csdn.net/article/details/108893062) |                                                              |
| [LeetCode 800. 相似 RGB 颜色](https://blog.csdn.net/qq_21201267/article/details/107095932) |                                                              |
| [LeetCode 801. 使序列递增的最小交换次数（动态规划）](https://michael.blog.csdn.net/article/details/105841553) |                                                              |
| [LeetCode 802. 找到最终的安全状态（逆向图+拓扑排序）](https://michael.blog.csdn.net/article/details/108864377) |                                                              |
| [LeetCode 803. 打砖块（并查集）](https://michael.blog.csdn.net/article/details/112723175) |                                                              |
| [LeetCode 804. 唯一摩尔斯密码词（哈希+set）](https://blog.csdn.net/qq_21201267/article/details/100630347) |                                                              |
| [LeetCode 806. 写字符串需要的行数](https://michael.blog.csdn.net/article/details/105776513) |                                                              |
| [LeetCode 807. 保持城市天际线](https://blog.csdn.net/qq_21201267/article/details/100585707) |                                                              |
| [LeetCode 808. 分汤（动态规划）](https://michael.blog.csdn.net/article/details/108636952) |                                                              |
| [LeetCode 809. 情感丰富的文字](https://michael.blog.csdn.net/article/details/109547018) |                                                              |
| [LeetCode 810. 黑板异或游戏（博弈推理）](https://michael.blog.csdn.net/article/details/106713569) |                                                              |
| [LeetCode 811. 子域名访问计数](https://michael.blog.csdn.net/article/details/105758279) |                                                              |
| [LeetCode 812. 最大三角形面积（坐标面积公式）](https://michael.blog.csdn.net/article/details/105758490) |                                                              |
| [LeetCode 813. 最大平均值和的分组（DP）](https://michael.blog.csdn.net/article/details/106860695) |                                                              |
| [LeetCode 814. 二叉树剪枝（递归）](https://blog.csdn.net/qq_21201267/article/details/100566646) |                                                              |
| [LeetCode 815. 公交路线（最少换乘，BFS）](https://michael.blog.csdn.net/article/details/106428528) |                                                              |
| [LeetCode 816. 模糊坐标](https://michael.blog.csdn.net/article/details/103942445) |                                                              |
| [LeetCode 817. 链表组件](https://michael.blog.csdn.net/article/details/105778063) |                                                              |
| [LeetCode 819. 最常见的单词](https://michael.blog.csdn.net/article/details/105762230) |                                                              |
| [LeetCode 820. 单词的压缩编码（后缀树）](https://michael.blog.csdn.net/article/details/105158592) |                                                              |
| [LeetCode 821. 字符的最短距离](https://blog.csdn.net/qq_21201267/article/details/101001770) |                                                              |
| [LeetCode 822. 翻转卡片游戏（哈希）](https://michael.blog.csdn.net/article/details/108925391) |                                                              |
| [LeetCode 823. 带因子的二叉树（动态规划）](https://michael.blog.csdn.net/article/details/108680229) |                                                              |
| [LeetCode 824. 山羊拉丁文](https://michael.blog.csdn.net/article/details/105762430) |                                                              |
| [LeetCode 825. 适龄的朋友（计数排序+前缀和）](https://michael.blog.csdn.net/article/details/108881492) |                                                              |
| [LeetCode 826. 安排工作以达到最大收益（map）](https://michael.blog.csdn.net/article/details/106320023) |                                                              |
| [LeetCode 827. 最大人工岛（BFS+哈希）](https://michael.blog.csdn.net/article/details/108896433) |                                                              |
| [LeetCode 828. 统计子串中的唯一字符（中心扩展）](https://michael.blog.csdn.net/article/details/107027774) |                                                              |
| [LeetCode 829. 连续整数求和（数学）](https://michael.blog.csdn.net/article/details/103501644) |                                                              |
| [LeetCode 830. 较大分组的位置](https://michael.blog.csdn.net/article/details/105775988) |                                                              |
| [LeetCode 831. 隐藏个人信息](https://michael.blog.csdn.net/article/details/107026868) |                                                              |
| [LeetCode 832. 翻转图像（异或^）](https://blog.csdn.net/qq_21201267/article/details/100585771) |                                                              |
| [LeetCode 833. 字符串中的查找与替换（排序，replace）](https://michael.blog.csdn.net/article/details/109686900) |                                                              |
| [LeetCode 834. 树中距离之和（树上DP）*](https://michael.blog.csdn.net/article/details/108937100) |                                                              |
| [LeetCode 835. 图像重叠](https://michael.blog.csdn.net/article/details/106858356) |                                                              |
| [LeetCode 836. 矩形重叠](https://michael.blog.csdn.net/article/details/105797392) |                                                              |
| [LeetCode 837. 新21点（动态规划）](https://michael.blog.csdn.net/article/details/106341826) |                                                              |
| [LeetCode 838. 推多米诺（模拟）](https://michael.blog.csdn.net/article/details/108663849) |                                                              |
| [LeetCode 839. 相似字符串组（并查集）](https://michael.blog.csdn.net/article/details/113458287) |                                                              |
| [LeetCode 840. 矩阵中的幻方（数学）](https://michael.blog.csdn.net/article/details/103192644) |                                                              |
| [LeetCode 841. 钥匙和房间（DFS/BFS）](https://blog.csdn.net/qq_21201267/article/details/101628381) |                                                              |
| [LeetCode 842. 将数组拆分成斐波那契序列（暴力查找）](https://michael.blog.csdn.net/article/details/103828495) |                                                              |
| [LeetCode 844. 比较含退格的字符串](https://michael.blog.csdn.net/article/details/105775248) |                                                              |
| [LeetCode 845. 数组中的最长山脉（中心扩展）](https://michael.blog.csdn.net/article/details/106295734) |                                                              |
| [LeetCode 846. 一手顺子（map）](https://michael.blog.csdn.net/article/details/106055016) |                                                              |
| [LeetCode 848. 字母移位（前缀和+取模）](https://michael.blog.csdn.net/article/details/108639423) |                                                              |
| [LeetCode 849. 到最近的人的最大距离](https://blog.csdn.net/qq_21201267/article/details/102903358) |                                                              |
| [LeetCode 851. 喧闹和富有（拓扑排序）](https://michael.blog.csdn.net/article/details/108791026) |                                                              |
| [LeetCode 852. 山脉数组的峰顶索引（二分查找）](https://blog.csdn.net/qq_21201267/article/details/100743518) |                                                              |
| [LeetCode 853. 车队（排序）](https://michael.blog.csdn.net/article/details/106425350) |                                                              |
| [LeetCode 856. 括号的分数](https://michael.blog.csdn.net/article/details/103527028) |                                                              |
| [LeetCode 858. 镜面反射（最小公倍数/最大公约数）](https://michael.blog.csdn.net/article/details/108645455) |                                                              |
| [LeetCode 859. 亲密字符串](https://michael.blog.csdn.net/article/details/105796587) |                                                              |
| [LeetCode 860. 柠檬水找零（贪心）](https://michael.blog.csdn.net/article/details/103153887) |                                                              |
| [LeetCode 861. 翻转矩阵后的得分（贪心）](https://michael.blog.csdn.net/article/details/103209591) |                                                              |
| [LeetCode 862. 和至少为 K 的最短子数组（前缀和+deque单调栈）](https://michael.blog.csdn.net/article/details/105662545) |                                                              |
| [LeetCode 863. 二叉树中所有距离为 K 的结点（公共祖先/ DFS+BFS）](https://michael.blog.csdn.net/article/details/106052376) |                                                              |
| [LeetCode 865. 具有所有最深结点的最小子树（递归）](https://michael.blog.csdn.net/article/details/105547677) |                                                              |
| [LeetCode 866. 回文素数（除11外，偶数位的回文数都不是质数）](https://michael.blog.csdn.net/article/details/105495449) |                                                              |
| [LeetCode 867. 转置矩阵](https://michael.blog.csdn.net/article/details/105796920) |                                                              |
| [LeetCode 868. 二进制间距（位运算）](https://blog.csdn.net/qq_21201267/article/details/101164748) |                                                              |
| [LeetCode 869. 重新排序得到 2 的幂（排序 & 全排列）](https://blog.csdn.net/qq_21201267/article/details/103096151) |                                                              |
| [LeetCode 870. 优势洗牌（贪心 & 二分查找）](https://michael.blog.csdn.net/article/details/103866966) |                                                              |
| [LeetCode 872. 叶子相似的树](https://michael.blog.csdn.net/article/details/105797294) |                                                              |
| [LeetCode 873. 最长的斐波那契子序列的长度（动态规划）](https://michael.blog.csdn.net/article/details/105821793) |                                                              |
| [LeetCode 874. 模拟行走机器人（set）](https://michael.blog.csdn.net/article/details/103192991) |                                                              |
| [LeetCode 875. 爱吃香蕉的珂珂（二分查找）](https://blog.csdn.net/qq_21201267/article/details/106313297) |                                                              |
| [LeetCode 876. 链表的中间结点（快慢指针）](https://blog.csdn.net/qq_21201267/article/details/101082616) |                                                              |
| [LeetCode 877. 石子游戏（DP）](https://michael.blog.csdn.net/article/details/105334918) |                                                              |
| [LeetCode 878. 第 N 个神奇数字（二分查找）](https://michael.blog.csdn.net/article/details/114757251) |                                                              |
| [LeetCode 879. 盈利计划（动态规划）](https://michael.blog.csdn.net/article/details/117756671) |                                                              |
| [LeetCode 880. 索引处的解码字符串（找规律）](https://michael.blog.csdn.net/article/details/112131756) |                                                              |
| [LeetCode 881. 救生艇（贪心，双指针）](https://michael.blog.csdn.net/article/details/103520322) |                                                              |
| [LeetCode 883. 三维形体投影面积](https://michael.blog.csdn.net/article/details/105797764) |                                                              |
| [LeetCode 884. 两句话中的不常见单词](https://michael.blog.csdn.net/article/details/105798465) |                                                              |
| [LeetCode 885. 螺旋矩阵 III](https://michael.blog.csdn.net/article/details/105747429) |                                                              |
| [LeetCode 886. 可能的二分法（着色DFS/BFS/拓展并查集）](https://michael.blog.csdn.net/article/details/106401724) |                                                              |
| [LeetCode 887. 鸡蛋掉落（DP，难）](https://blog.csdn.net/qq_21201267/article/details/102844454) |                                                              |
| [LeetCode 888. 公平的糖果交换（哈希set）](https://michael.blog.csdn.net/article/details/103168073) |                                                              |
| [LeetCode 889. 已知前序&后序 求二叉树（不唯一）](https://blog.csdn.net/qq_21201267/article/details/100802843) |                                                              |
| [LeetCode 890. 查找和替换模式（哈希表）](https://michael.blog.csdn.net/article/details/103214178) |                                                              |
| [LeetCode 891. 子序列宽度之和（数学）](https://michael.blog.csdn.net/article/details/114190097) |                                                              |
| [LeetCode 892. 三维形体的表面积（数学）](https://michael.blog.csdn.net/article/details/103153550) |                                                              |
| [LeetCode 893. 特殊等价字符串组](https://michael.blog.csdn.net/article/details/105798555) |                                                              |
| [LeetCode 894. 所有可能的满二叉树（递归）](https://michael.blog.csdn.net/article/details/105727867) |                                                              |
| [LeetCode 895. 最大频率栈（哈希+按频数存储）](https://michael.blog.csdn.net/article/details/107324296) |                                                              |
| [LeetCode 896. 单调数列](https://blog.csdn.net/qq_21201267/article/details/100782385) |                                                              |
| [LeetCode 897. 递增顺序查找树（中序遍历）](https://blog.csdn.net/qq_21201267/article/details/101083541) |                                                              |
| [LeetCode 898. 子数组按位或操作（前缀和思想）](https://michael.blog.csdn.net/article/details/112366460) |                                                              |
| [LeetCode 900. RLE 迭代器（模拟/二分查找）](https://michael.blog.csdn.net/article/details/108658180) |                                                              |
| [LeetCode 901. 股票价格跨度（单调栈）](https://michael.blog.csdn.net/article/details/105860583) |                                                              |
| [LeetCode 904. 水果成篮（滑动窗口）](https://michael.blog.csdn.net/article/details/106556066) |                                                              |
| [LeetCode 905. 按奇偶排序数组](https://blog.csdn.net/qq_21201267/article/details/100940305) |                                                              |
| [LeetCode 907. 子数组的最小值之和（单调栈）](https://michael.blog.csdn.net/article/details/112326435) |                                                              |
| [LeetCode 908. 最小差值 I](https://blog.csdn.net/qq_21201267/article/details/100944337) |                                                              |
| [LeetCode 909. 蛇梯棋（BFS）](https://michael.blog.csdn.net/article/details/109138207) |                                                              |
| [LeetCode 910. 最小差值 II（贪心）](https://michael.blog.csdn.net/article/details/106576338) |                                                              |
| [LeetCode 911. 在线选举（二分查找）](https://michael.blog.csdn.net/article/details/108632844) |                                                              |
| [LeetCode 912. 排序数组（10种排序）](https://blog.csdn.net/qq_21201267/article/details/105216430) |                                                              |
| [LeetCode 914. 卡牌分组（最大公约数）](https://michael.blog.csdn.net/article/details/103044009) |                                                              |
| [LeetCode 915. 分割数组](https://michael.blog.csdn.net/article/details/109667141) |                                                              |
| [LeetCode 916. 单词子集（计数）](https://michael.blog.csdn.net/article/details/105681007) |                                                              |
| [LeetCode 917. 仅仅反转字母](https://michael.blog.csdn.net/article/details/105799219) |                                                              |
| [LeetCode 918. 环形子数组的最大和（前缀和+单调队列）](https://michael.blog.csdn.net/article/details/112985188) |                                                              |
| [LeetCode 919. 完全二叉树插入器（层序遍历&队列）](https://michael.blog.csdn.net/article/details/103108605) |                                                              |
| [LeetCode 921. 使括号有效的最少添加（栈）](https://michael.blog.csdn.net/article/details/105799322) |                                                              |
| [LeetCode 922. 按奇偶排序数组 II（双指针）](https://blog.csdn.net/qq_21201267/article/details/100998177) |                                                              |
| [LeetCode 923. 三数之和的多种可能（双指针）](https://michael.blog.csdn.net/article/details/106034888) |                                                              |
| [LeetCode 925. 长按键入（双指针）](https://michael.blog.csdn.net/article/details/105800254) |                                                              |
| [LeetCode 926. 将字符串翻转到单调递增（动态规划）](https://michael.blog.csdn.net/article/details/108789082) |                                                              |
| [LeetCode 927. 三等分（模拟）](https://michael.blog.csdn.net/article/details/112694140) |                                                              |
| [LeetCode 929. 独特的电子邮件地址](https://michael.blog.csdn.net/article/details/105804981) |                                                              |
| [LeetCode 930. 和相同的二元子数组（哈希+前缀和）](https://michael.blog.csdn.net/article/details/108593514) |                                                              |
| [LeetCode 931. 下降路径最小和（动态规划）](https://michael.blog.csdn.net/article/details/105804834) |                                                              |
| [LeetCode 932. 漂亮数组（分治递归/循环）](https://michael.blog.csdn.net/article/details/106279389) |                                                              |
| [LeetCode 933. 最近的请求次数（queue）](https://blog.csdn.net/qq_21201267/article/details/100746524) |                                                              |
| [LeetCode 934. 最短的桥（2次BFS）](https://michael.blog.csdn.net/article/details/103938366) |                                                              |
| [LeetCode 935. 骑士拨号器（动态规划）](https://michael.blog.csdn.net/article/details/108922475) |                                                              |
| [LeetCode 937. 重新排列日志文件（自定义排序）](https://blog.csdn.net/qq_21201267/article/details/103171169) |                                                              |
| [LeetCode 938. 二叉搜索树的范围和（二叉树遍历+搜索剪枝）](https://blog.csdn.net/qq_21201267/article/details/100609270) |                                                              |
| [LeetCode 939. 最小面积矩形（哈希）](https://michael.blog.csdn.net/article/details/108053430) |                                                              |
| [LeetCode 940. 不同的子序列 II（动态规划）](https://michael.blog.csdn.net/article/details/112290401) |                                                              |
| [LeetCode 941. 有效的山脉数组](https://michael.blog.csdn.net/article/details/105804816) |                                                              |
| [LeetCode 942. 增减字符串匹配](https://blog.csdn.net/qq_21201267/article/details/100907468) |                                                              |
| [LeetCode 944. 删列造序](https://blog.csdn.net/qq_21201267/article/details/100675384) |                                                              |
| [LeetCode 945. 使数组唯一的最小增量（贪心）](https://blog.csdn.net/qq_21201267/article/details/105032960) |                                                              |
| [LeetCode 946. 验证栈序列（栈）](https://michael.blog.csdn.net/article/details/103566492) |                                                              |
| [LeetCode 947. 移除最多的同行或同列石头（并查集）](https://michael.blog.csdn.net/article/details/106795331) |                                                              |
| [LeetCode 948. 令牌放置（贪心）](https://michael.blog.csdn.net/article/details/108899901) |                                                              |
| [LeetCode 949. 给定数字能组成的最大时间（暴力）](https://michael.blog.csdn.net/article/details/105804878) |                                                              |
| [LeetCode 950. 按递增顺序显示卡牌（deque）](https://blog.csdn.net/qq_21201267/article/details/100608442) |                                                              |
| [LeetCode 951. 翻转等价二叉树（递归）](https://michael.blog.csdn.net/article/details/102998305) |                                                              |
| [LeetCode 953. 验证外星语词典](https://michael.blog.csdn.net/article/details/105805098) |                                                              |
| [LeetCode 954. 二倍数对数组（map计数）](https://michael.blog.csdn.net/article/details/108884093) |                                                              |
| [LeetCode 956. 最高的广告牌（DP）](https://michael.blog.csdn.net/article/details/109004965) |                                                              |
| [LeetCode 957. N 天后的牢房（查找循环节）](https://michael.blog.csdn.net/article/details/106769878) |                                                              |
| [LeetCode 958. 二叉树的完全性检验（层序遍历）](https://michael.blog.csdn.net/article/details/103101797) |                                                              |
| [LeetCode 959. 由斜杠划分区域（并查集）](https://michael.blog.csdn.net/article/details/105739007) |                                                              |
| [LeetCode 961. 重复 N 次的元素](https://michael.blog.csdn.net/article/details/105800069) |                                                              |
| [LeetCode 962. 最大宽度坡（单调栈）](https://michael.blog.csdn.net/article/details/106057212) |                                                              |
| [LeetCode 963. 最小面积矩形 II](https://michael.blog.csdn.net/article/details/112982307) |                                                              |
| [LeetCode 965. 单值二叉树](https://blog.csdn.net/qq_21201267/article/details/100993432) |                                                              |
| [LeetCode 966. 元音拼写检查器（哈希）](https://michael.blog.csdn.net/article/details/106875371) |                                                              |
| [LeetCode 967. 连续差相同的数字（BFS/DFS）](https://michael.blog.csdn.net/article/details/108473159) |                                                              |
| [LeetCode 968. 监控二叉树（DFS）](https://michael.blog.csdn.net/article/details/108725155) |                                                              |
| [LeetCode 969. 煎饼排序](https://blog.csdn.net/qq_21201267/article/details/100797632) |                                                              |
| [LeetCode 970. 强整数](https://blog.csdn.net/qq_21201267/article/details/102889287) |                                                              |
| [LeetCode 971. 翻转二叉树以匹配先序遍历（DFS）](https://michael.blog.csdn.net/article/details/106876360) |                                                              |
| [LeetCode 973. 最接近原点的 K 个点（排序/优先队列/快排）](https://michael.blog.csdn.net/article/details/105969787) |                                                              |
| [LeetCode 974. 和可被 K 整除的子数组（哈希map）](https://michael.blog.csdn.net/article/details/106373050) |                                                              |
| [LeetCode 976. 三角形的最大周长](https://michael.blog.csdn.net/article/details/105778251) |                                                              |
| [LeetCode 977. 有序数组的平方](https://blog.csdn.net/qq_21201267/article/details/100057616) |                                                              |
| [LeetCode 978. 最长湍流子数组（DP）](https://michael.blog.csdn.net/article/details/106590866) |                                                              |
| [LeetCode 979. 在二叉树中分配硬币（DFS）](https://michael.blog.csdn.net/article/details/103219540) |                                                              |
| [LeetCode 980. 不同路径 III（DFS+回溯）](https://michael.blog.csdn.net/article/details/102961910) |                                                              |
| [LeetCode 981. 基于时间的键值存储（哈希+二分查找）](https://michael.blog.csdn.net/article/details/108792600) |                                                              |
| [LeetCode 982. 按位与为零的三元组（位运算+计数）](https://michael.blog.csdn.net/article/details/112094671) |                                                              |
| [LeetCode 983. 最低票价（动态规划）](https://michael.blog.csdn.net/article/details/105948343) |                                                              |
| [LeetCode 984. 不含 AAA 或 BBB 的字符串（贪心）](https://michael.blog.csdn.net/article/details/103883367) |                                                              |
| [LeetCode 985. 查询后的偶数和](https://michael.blog.csdn.net/article/details/105758689) |                                                              |
| [LeetCode 986. 区间列表的交集](https://blog.csdn.net/qq_21201267/article/details/100058783) |                                                              |
| [LeetCode 987. 二叉树的垂序遍历（递归/循环）](https://michael.blog.csdn.net/article/details/105681731) |                                                              |
| [LeetCode 988. 从叶结点开始的最小字符串（DFS）](https://michael.blog.csdn.net/article/details/108757864) |                                                              |
| [LeetCode 989. 数组形式的整数加法](https://michael.blog.csdn.net/article/details/103020342) |                                                              |
| [LeetCode 990. 等式方程的可满足性（并查集）](https://michael.blog.csdn.net/article/details/106354260) |                                                              |
| [LeetCode 991. 坏了的计算器（逆向思考）](https://michael.blog.csdn.net/article/details/103498206) |                                                              |
| [LeetCode 992. K 个不同整数的子数组（双指针）](https://michael.blog.csdn.net/article/details/113773415) |                                                              |
| [LeetCode 993. 二叉树的堂兄弟节点（层序遍历）](https://michael.blog.csdn.net/article/details/103113397) |                                                              |
| [LeetCode 994. 腐烂的橘子（图的BFS）](https://blog.csdn.net/qq_21201267/article/details/102906778) |                                                              |
| [LeetCode 995. K 连续位的最小翻转次数（差分思想）](https://michael.blog.csdn.net/article/details/110858906) |                                                              |
| [LeetCode 996. 正方形数组的数目（回溯+剪枝）](https://michael.blog.csdn.net/article/details/108927702) |                                                              |
| [LeetCode 997. 找到小镇的法官（图的出度和入度）](https://michael.blog.csdn.net/article/details/103174525) |                                                              |
| [LeetCode 998. 最大二叉树 II](https://blog.csdn.net/qq_21201267/article/details/100785910) |                                                              |
| [LeetCode 999. 车的可用捕获量](https://michael.blog.csdn.net/article/details/105108754) |                                                              |
| [LeetCode 1000. 合并石头的最低成本（区间DP）](http://michael.blog.csdn.net/article/details/110825691) |                                                              |
| [LeetCode 1002. 查找常用字符（哈希）](https://blog.csdn.net/qq_21201267/article/details/100997357) |                                                              |
| [LeetCode 1003. 检查替换后的词是否有效（栈）](https://michael.blog.csdn.net/article/details/103509100) |                                                              |
| [LeetCode 1004. 最大连续1的个数 III（滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/100855871) |                                                              |
| [LeetCode 1005. K 次取反后最大化的数组和](https://michael.blog.csdn.net/article/details/105758899) |                                                              |
| [LeetCode 1006. 笨阶乘](https://michael.blog.csdn.net/article/details/103220417) |                                                              |
| [LeetCode 1007. 行相等的最少多米诺旋转](https://michael.blog.csdn.net/article/details/108897096) |                                                              |
| [LeetCode 1008. 先序遍历构造二叉树（已知先序，求二叉搜索树）](https://blog.csdn.net/qq_21201267/article/details/100568701) |                                                              |
| [LeetCode 1009. 十进制整数的反码（位运算）](https://blog.csdn.net/qq_21201267/article/details/101197758) |                                                              |
| [LeetCode 1010. 总持续时间可被 60 整除的歌曲（哈希）](https://michael.blog.csdn.net/article/details/103190028) |                                                              |
| [LeetCode 1011. 在 D 天内送达包裹的能力（二分查找）](https://michael.blog.csdn.net/article/details/106300796) |                                                              |
| [LeetCode 1013. 将数组分成和相等的三个部分](https://michael.blog.csdn.net/article/details/103154010) |                                                              |
| [LeetCode 1014. 最佳观光组合](https://michael.blog.csdn.net/article/details/103316755) |                                                              |
| [LeetCode 1015. 可被 K 整除的最小整数（数学）](https://michael.blog.csdn.net/article/details/106029928) |                                                              |
| [LeetCode 1016. 子串能表示从 1 到 N 数字的二进制串（bitset）](https://michael.blog.csdn.net/article/details/103530223) |                                                              |
| [LeetCode 1017. 负二进制转换（负数进制转换）](https://michael.blog.csdn.net/article/details/103430094) |                                                              |
| [LeetCode 1018. 可被 5 整除的二进制前缀](https://michael.blog.csdn.net/article/details/105799833) |                                                              |
| [LeetCode 1019. 链表中的下一个更大节点（单调栈）](https://michael.blog.csdn.net/article/details/103796861) |                                                              |
| [LeetCode 1020. 飞地的数量（图的BFS/DFS）](https://michael.blog.csdn.net/article/details/103523525) |                                                              |
| [LeetCode 1021. 删除最外层的括号（栈）](https://blog.csdn.net/qq_21201267/article/details/100611450) |                                                              |
| [LeetCode 1022. 从根到叶的二进制数之和（递归）](https://michael.blog.csdn.net/article/details/103058521) |                                                              |
| [LeetCode 1023. 驼峰式匹配（暴力匹配）](https://michael.blog.csdn.net/article/details/103517033) |                                                              |
| [LeetCode 1024. 视频拼接（动态规划/贪心）](https://michael.blog.csdn.net/article/details/109129842) |                                                              |
| [LeetCode 1025. 除数博弈（动态规划）](https://michael.blog.csdn.net/article/details/105809852) |                                                              |
| [LeetCode 1026. 节点与其祖先之间的最大差值（二叉树DFS）](https://michael.blog.csdn.net/article/details/103357890) |                                                              |
| [LeetCode 1027. 最长等差数列（DP）](https://michael.blog.csdn.net/article/details/106820302) |                                                              |
| [LeetCode 1028. 从先序遍历还原二叉树（栈）](https://michael.blog.csdn.net/article/details/103002761) |                                                              |
| [LeetCode 1029. 两地调度（贪心）](https://michael.blog.csdn.net/article/details/103003479) |                                                              |
| [LeetCode 1030. 距离顺序排列矩阵单元格（排序&Lambda表达式&BFS）](https://michael.blog.csdn.net/article/details/103151131) |                                                              |
| [LeetCode 1031. 两个非重叠子数组的最大和（一次遍历，要复习）*](https://michael.blog.csdn.net/article/details/108614192) |                                                              |
| [LeetCode 1033. 移动石子直到连续](https://michael.blog.csdn.net/article/details/105805226) |                                                              |
| [LeetCode 1034. 边框着色（BFS/DFS）](https://michael.blog.csdn.net/article/details/108521257) |                                                              |
| [LeetCode 1035. 不相交的线（最长公共子序列DP）](https://michael.blog.csdn.net/article/details/107995224) |                                                              |
| [LeetCode 1037. 有效的回旋镖](https://michael.blog.csdn.net/article/details/105805499) |                                                              |
| [LeetCode 1038. 从二叉搜索树到更大和树（逆中序-右根左-降序）](https://blog.csdn.net/qq_21201267/article/details/100798009) |                                                              |
| [LeetCode 1039. 多边形三角剖分的最低得分（区间DP）](https://michael.blog.csdn.net/article/details/108408580) |                                                              |
| [LeetCode 1041. 困于环中的机器人](https://michael.blog.csdn.net/article/details/108401029) |                                                              |
| [LeetCode 1042. 不邻接植花（图的数据结构）](https://michael.blog.csdn.net/article/details/103076199) |                                                              |
| [LeetCode 1043. 分隔数组以得到最大和（DP）](https://michael.blog.csdn.net/article/details/103285753) |                                                              |
| [LeetCode 1046. 最后一块石头的重量（priority_queue 堆）](https://blog.csdn.net/qq_21201267/article/details/101215370) |                                                              |
| [LeetCode 1047. 删除字符串中的所有相邻重复项（栈）](https://blog.csdn.net/qq_21201267/article/details/101083067) |                                                              |
| [LeetCode 1048. 最长字符串链（哈希+DP）](https://michael.blog.csdn.net/article/details/108518244) |                                                              |
| [LeetCode 1049. 最后一块石头的重量 II（DP）](https://michael.blog.csdn.net/article/details/106980126) |                                                              |
| [LeetCode 1051. 高度检查器](https://blog.csdn.net/qq_21201267/article/details/100635273) |                                                              |
| [LeetCode 1052. 爱生气的书店老板（滑动窗口）](https://michael.blog.csdn.net/article/details/103328664) |                                                              |
| [LeetCode 1053. 交换一次的先前排列](https://michael.blog.csdn.net/article/details/107029805) |                                                              |
| [LeetCode 1054. 距离相等的条形码（优先队列）](https://blog.csdn.net/qq_21201267/article/details/104317529) |                                                              |
| [LeetCode 1055. 形成字符串的最短路径（贪心）](https://michael.blog.csdn.net/article/details/107848565) |                                                              |
| [LeetCode 1056. 易混淆数（哈希）](https://blog.csdn.net/qq_21201267/article/details/107105777) |                                                              |
| [LeetCode 1057. 校园自行车分配（map有序+贪心）](https://michael.blog.csdn.net/article/details/107822070) |                                                              |
| [LeetCode 1058. 最小化舍入误差以满足目标（排序+贪心）](https://michael.blog.csdn.net/article/details/107848213) |                                                              |
| [LeetCode 1059. 从始点到终点的所有路径（回溯）](https://michael.blog.csdn.net/article/details/107847149) |                                                              |
| [LeetCode 1060. 有序数组中的缺失元素（二分查找）](https://michael.blog.csdn.net/article/details/107538389) |                                                              |
| [LeetCode 1061. 按字典序排列最小的等效字符串（并查集）](https://blog.csdn.net/qq_21201267/article/details/107149147) |                                                              |
| [LeetCode 1062. 最长重复子串（二分查找）](https://michael.blog.csdn.net/article/details/107543705) |                                                              |
| [LeetCode 1063. 有效子数组的数目（单调栈）](https://michael.blog.csdn.net/article/details/107522174) |                                                              |
| [LeetCode 1064. 不动点（二分查找）](https://blog.csdn.net/qq_21201267/article/details/107094877) |                                                              |
| [LeetCode 1065. 字符串的索引对](https://blog.csdn.net/qq_21201267/article/details/107097461) |                                                              |
| [LeetCode 1066. 校园自行车分配 II（状态压缩DP）](https://michael.blog.csdn.net/article/details/107876440) |                                                              |
| [LeetCode 1067. 范围内的数字计数](https://michael.blog.csdn.net/article/details/107771796) |                                                              |
| [LeetCode 1071. 字符串的最大公因子（字符串的最大公约数）](https://michael.blog.csdn.net/article/details/103174953) |                                                              |
| [LeetCode 1072. 按列翻转得到最大值等行数（查找相同的模式，哈希计数）](https://michael.blog.csdn.net/article/details/106972120) |                                                              |
| [LeetCode 1073. 负二进制数相加（负数进制）](https://michael.blog.csdn.net/article/details/103899481) |                                                              |
| [LeetCode 1074. 元素和为目标值的子矩阵数量（2d前缀和+哈希）](https://michael.blog.csdn.net/article/details/112093880) |                                                              |
| [LeetCode 1078. Bigram 分词](https://blog.csdn.net/qq_21201267/article/details/101173096) |                                                              |
| [LeetCode 1079. 活字印刷（全排列回溯）](https://blog.csdn.net/qq_21201267/article/details/100644009) |                                                              |
| [LeetCode 1080. 根到叶路径上的不足节点（递归）](https://michael.blog.csdn.net/article/details/103690245) |                                                              |
| [LeetCode 1081. 不同字符的最小子序列（单调栈）](https://michael.blog.csdn.net/article/details/109538681) |                                                              |
| [LeetCode 1085. 最小元素各数位之和](https://blog.csdn.net/qq_21201267/article/details/107093866) |                                                              |
| [LeetCode 1086. 前五科的均分（map + 优先队列）](https://blog.csdn.net/qq_21201267/article/details/107094524) |                                                              |
| [LeetCode 1087. 字母切换（回溯）](https://michael.blog.csdn.net/article/details/107541722) |                                                              |
| [LeetCode 1088. 易混淆数 II（回溯/BFS）](https://michael.blog.csdn.net/article/details/107966008) |                                                              |
| [LeetCode 1089. 复写零](https://blog.csdn.net/qq_21201267/article/details/100809393) |                                                              |
| [LeetCode 1090. 受标签影响的最大值（优先队列）](https://michael.blog.csdn.net/article/details/106679683) |                                                              |
| [LeetCode 1091. 二进制矩阵中的最短路径（BFS）](https://michael.blog.csdn.net/article/details/106029651) |                                                              |
| [LeetCode 1093. 大样本统计](https://michael.blog.csdn.net/article/details/105802780) |                                                              |
| [LeetCode 1094. 拼车](https://blog.csdn.net/qq_21201267/article/details/100604925) |                                                              |
| [LeetCode 1095. 山脉数组中查找目标值（二分查找）](https://michael.blog.csdn.net/article/details/105837135) |                                                              |
| [LeetCode 1099. 小于 K 的两数之和（二分查找）](https://blog.csdn.net/qq_21201267/article/details/107097354) |                                                              |
| [LeetCode 1100. 长度为 K 的无重复字符子串（滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/107123609) |                                                              |
| [LeetCode 1101. 彼此熟识的最早时间（排序+并查集）](https://blog.csdn.net/qq_21201267/article/details/107127601) |                                                              |
| [LeetCode 1102. 得分最高的路径（优先队列BFS/极大极小化 二分查找）](https://michael.blog.csdn.net/article/details/107868938) |                                                              |
| [LeetCode 1103. 分糖果 II](https://blog.csdn.net/qq_21201267/article/details/100802416) |                                                              |
| [LeetCode 1104. 二叉树寻路（数学&位运算）](https://michael.blog.csdn.net/article/details/103100853) |                                                              |
| [LeetCode 1105. 填充书架（DP）](https://michael.blog.csdn.net/article/details/114410707) |                                                              |
| [LeetCode 1108. IP 地址无效化](https://blog.csdn.net/qq_21201267/article/details/100585842) |                                                              |
| [LeetCode 1109. 航班预订统计（差分思想）](https://michael.blog.csdn.net/article/details/106423509) |                                                              |
| [LeetCode 1110. 删点成林（二叉树递归）](https://michael.blog.csdn.net/article/details/105968905) |                                                              |
| [LeetCode 1111. 有效括号的嵌套深度（奇偶分离）](https://michael.blog.csdn.net/article/details/105243722) |                                                              |
| [LeetCode 1118. 一月有多少天（闰年判断）](https://blog.csdn.net/qq_21201267/article/details/107096957) |                                                              |
| [LeetCode 1119. 删去字符串中的元音](https://blog.csdn.net/qq_21201267/article/details/107092684) |                                                              |
| [LeetCode 1120. 子树的最大平均值（DFS自底向上）](https://blog.csdn.net/qq_21201267/article/details/107123249) |                                                              |
| [LeetCode 1121. 将数组分成几个递增序列](https://michael.blog.csdn.net/article/details/107575232) |                                                              |
| [LeetCode 1122. 数组的相对排序](https://blog.csdn.net/qq_21201267/article/details/101112047) |                                                              |
| [LeetCode 1123. 最深叶节点的最近公共祖先（递归比较子树高度）](https://michael.blog.csdn.net/article/details/105547346) |                                                              |
| [LeetCode 1124. 表现良好的最长时间段（单调栈/哈希）](https://michael.blog.csdn.net/article/details/108536922) |                                                              |
| [LeetCode 1128. 等价多米诺骨牌对的数量（哈希）](https://michael.blog.csdn.net/article/details/103190477) |                                                              |
| [LeetCode 1129. 颜色交替的最短路径（BFS）](https://michael.blog.csdn.net/article/details/108389915) |                                                              |
| [LeetCode 1130. 叶值的最小代价生成树（区间DP/单调栈贪心）](https://michael.blog.csdn.net/article/details/108581070) |                                                              |
| [LeetCode 1131. 绝对值表达式的最大值（数学 绝对值展开）](https://michael.blog.csdn.net/article/details/108060835) |                                                              |
| [LeetCode 1133. 最大唯一数](https://blog.csdn.net/qq_21201267/article/details/107097303) |                                                              |
| [LeetCode 1134. 阿姆斯特朗数](https://blog.csdn.net/qq_21201267/article/details/107093934) |                                                              |
| [LeetCode 1135. 最低成本联通所有城市（最小生成树+排序+并查集）](https://michael.blog.csdn.net/article/details/107796632) |                                                              |
| [LeetCode 1136. 平行课程（拓扑排序）](https://michael.blog.csdn.net/article/details/107749482) |                                                              |
| [LeetCode 1137. 第 N 个泰波那契数](https://blog.csdn.net/qq_21201267/article/details/100671814) |                                                              |
| [LeetCode 1138. 字母板上的路径](https://michael.blog.csdn.net/article/details/103899893) |                                                              |
| [LeetCode 1139. 最大的以 1 为边界的正方形（DP）](https://michael.blog.csdn.net/article/details/105542359) |                                                              |
| [LeetCode 1140. 石子游戏 II（DP）*](https://michael.blog.csdn.net/article/details/108034600) |                                                              |
| [LeetCode 1143. 最长公共子序列（动态规划）](https://michael.blog.csdn.net/article/details/105789592) |                                                              |
| [LeetCode 1144. 递减元素使数组呈锯齿状（奇偶分别遍历）](https://michael.blog.csdn.net/article/details/106599943) |                                                              |
| [LeetCode 1145. 二叉树着色游戏（计算节点个数）](https://michael.blog.csdn.net/article/details/103115240) |                                                              |
| [LeetCode 1146. 快照数组（哈希map + 有序map）](https://michael.blog.csdn.net/article/details/108879748) |                                                              |
| [LeetCode 1147. 段式回文（贪心）](https://michael.blog.csdn.net/article/details/112095161) |                                                              |
| [LeetCode 1150. 检查一个数是否在数组中占绝大多数（二分查找）](https://blog.csdn.net/qq_21201267/article/details/107096729) |                                                              |
| [LeetCode 1151. 最少交换次数来组合所有的 1（滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/107210414) |                                                              |
| [LeetCode 1152. 用户网站访问行为分析](https://michael.blog.csdn.net/article/details/107784313) |                                                              |
| [LeetCode 1153. 字符串转化（哈希）](https://michael.blog.csdn.net/article/details/107991371) |                                                              |
| [LeetCode 1154. 一年中的第几天](https://blog.csdn.net/qq_21201267/article/details/100754099) |                                                              |
| [LeetCode 1155. 掷骰子的N种方法（DP）](https://michael.blog.csdn.net/article/details/106673138) |                                                              |
| [LeetCode 1156. 单字符重复子串的最大长度](https://michael.blog.csdn.net/article/details/112993340) |                                                              |
| [LeetCode 1160. 拼写单词](https://blog.csdn.net/qq_21201267/article/details/100673250) |                                                              |
| [LeetCode 1161. 最大层内元素和（层序遍历）](https://michael.blog.csdn.net/article/details/103216744) |                                                              |
| [LeetCode 1162. 地图分析（BFS）](https://michael.blog.csdn.net/article/details/105172033) |                                                              |
| [LeetCode 1165. 单行键盘（哈希）](https://blog.csdn.net/qq_21201267/article/details/107093125) |                                                              |
| [LeetCode 1166. 设计文件系统（哈希map）](https://michael.blog.csdn.net/article/details/107542532) |                                                              |
| [LeetCode 1167. 连接棒材的最低费用（优先队列+贪心）](https://michael.blog.csdn.net/article/details/107786477) |                                                              |
| [LeetCode 1169. 查询无效交易](https://michael.blog.csdn.net/article/details/106583761) |                                                              |
| [LeetCode 1170. 比较字符串最小字母出现频次](https://michael.blog.csdn.net/article/details/105803059) |                                                              |
| [LeetCode 1171. 从链表中删去总和值为零的连续节点（哈希表）](https://michael.blog.csdn.net/article/details/102925963) |                                                              |
| [LeetCode 1172. 餐盘栈（栈 + set）](https://michael.blog.csdn.net/article/details/103328021) |                                                              |
| [LeetCode 1175. 质数排列](https://blog.csdn.net/qq_21201267/article/details/100612707) |                                                              |
| [LeetCode 1176. 健身计划评估（滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/107104482) |                                                              |
| [LeetCode 1177. 构建回文串检测（前缀和）](https://michael.blog.csdn.net/article/details/105498437) |                                                              |
| [LeetCode 1178. 猜字谜（状态压缩+枚举二进制子集+哈希）](https://michael.blog.csdn.net/article/details/114112247) |                                                              |
| [LeetCode 1180. 统计只含单一字母的子串](https://blog.csdn.net/qq_21201267/article/details/107094297) |                                                              |
| [LeetCode 1181. 前后拼接（哈希map）](https://michael.blog.csdn.net/article/details/107790829) |                                                              |
| [LeetCode 1182. 与目标颜色间的最短距离（二分查找/DP）](https://michael.blog.csdn.net/article/details/107644302) |                                                              |
| [LeetCode 1184. 公交站间的距离](https://blog.csdn.net/qq_21201267/article/details/100814178) |                                                              |
| [LeetCode 1185. 一周中的第几天](https://blog.csdn.net/qq_21201267/article/details/100808636) |                                                              |
| [LeetCode 1186. 删除一次得到子数组最大和（DP）](https://michael.blog.csdn.net/article/details/106534231) |                                                              |
| [LeetCode 1187. 使数组严格递增（DP）*](https://michael.blog.csdn.net/article/details/111991901) |                                                              |
| [LeetCode 1189. “气球” 的最大数量](https://michael.blog.csdn.net/article/details/105803005) |                                                              |
| [LeetCode 1190. 反转每对括号间的子串（栈）](https://michael.blog.csdn.net/article/details/103796323) |                                                              |
| [LeetCode 1191. K 次串联后最大子数组之和（前缀和+分类讨论）](https://michael.blog.csdn.net/article/details/115017417) |                                                              |
| [LeetCode 1196. 最多可以买到的苹果数量（贪心）](https://blog.csdn.net/qq_21201267/article/details/107094727) |                                                              |
| [LeetCode 1197. 进击的骑士（BFS）](https://michael.blog.csdn.net/article/details/107785390) |                                                              |
| [LeetCode 1198. 找出所有行中最小公共元素（二分/合并有序链表）](https://blog.csdn.net/qq_21201267/article/details/107116021) |                                                              |
| [LeetCode 1199. 建造街区的最短时间（优先队列贪心）](https://michael.blog.csdn.net/article/details/107965322) |                                                              |
| [LeetCode 1200. 最小绝对差](https://michael.blog.csdn.net/article/details/105802282) |                                                              |
| [LeetCode 1201. 丑数 III（最小公倍数+二分查找）](https://michael.blog.csdn.net/article/details/105920352) |                                                              |
| [LeetCode 1202. 交换字符串中的元素（并查集）](https://michael.blog.csdn.net/article/details/106042356) |                                                              |
| [LeetCode 1203. 项目管理（两次拓扑排序）](https://michael.blog.csdn.net/article/details/112546098) |                                                              |
| [LeetCode 1207. 独一无二的出现次数](https://michael.blog.csdn.net/article/details/105802661) |                                                              |
| [LeetCode 1208. 尽可能使字符串相等（滑动窗口）](https://michael.blog.csdn.net/article/details/103324980) |                                                              |
| [LeetCode 1209. 删除字符串中的所有相邻重复项 II（栈）](https://michael.blog.csdn.net/article/details/103325673) |                                                              |
| [LeetCode 1210. 穿过迷宫的最少移动次数（状态压缩BFS）](https://michael.blog.csdn.net/article/details/108962523) |                                                              |
| [LeetCode 1213. 三个有序数组的交集（哈希set）](https://blog.csdn.net/qq_21201267/article/details/107093759) |                                                              |
| [LeetCode 1214. 查找两棵二叉搜索树之和（二叉树迭代器+双指针）](https://blog.csdn.net/qq_21201267/article/details/107121498) |                                                              |
| [LeetCode 1215. 步进数（BFS/DFS）](https://michael.blog.csdn.net/article/details/107581522) |                                                              |
| [LeetCode 1216. 验证回文字符串 III（DP）](https://michael.blog.csdn.net/article/details/107782226) |                                                              |
| [LeetCode 1217. 玩筹码（脑筋急转弯）](https://michael.blog.csdn.net/article/details/105802562) |                                                              |
| [LeetCode 1218. 最长定差子序列（哈希map）](https://michael.blog.csdn.net/article/details/106817938) |                                                              |
| [LeetCode 1219. 黄金矿工（回溯）](https://michael.blog.csdn.net/article/details/102999022) |                                                              |
| [LeetCode 1220. 统计元音字母序列的数目（DP）](https://michael.blog.csdn.net/article/details/108960182) |                                                              |
| [LeetCode 1221. 分割平衡字符串](https://michael.blog.csdn.net/article/details/105802345) |                                                              |
| [LeetCode 1222. 可以攻击国王的皇后（set）](https://michael.blog.csdn.net/article/details/105802412) |                                                              |
| [LeetCode 1223. 掷骰子模拟（DP）](https://michael.blog.csdn.net/article/details/106675048) |                                                              |
| [LeetCode 1224. 最大相等频率（哈希）](https://michael.blog.csdn.net/article/details/111896985) |                                                              |
| [LeetCode 1227. 飞机座位分配概率（DP+数学归纳法）](https://michael.blog.csdn.net/article/details/105805627) |                                                              |
| [LeetCode 1228. 等差数列中缺失的数字](https://blog.csdn.net/qq_21201267/article/details/107097382) |                                                              |
| [LeetCode 1229. 安排会议日程（双指针）](https://michael.blog.csdn.net/article/details/107643939) |                                                              |
| [LeetCode 1230. 抛掷硬币（DP）](https://michael.blog.csdn.net/article/details/107577040) |                                                              |
| [LeetCode 1231. 分享巧克力（极小极大化 二分查找）](https://michael.blog.csdn.net/article/details/107534172) |                                                              |
| [LeetCode 1232. 缀点成线](https://michael.blog.csdn.net/article/details/105802054) |                                                              |
| [LeetCode 1233. 删除子文件夹](https://michael.blog.csdn.net/article/details/103916724) |                                                              |
| [LeetCode 1234. 替换子串得到平衡字符串（滑动窗口）](https://michael.blog.csdn.net/article/details/106587538) |                                                              |
| [LeetCode 1235. 规划兼职工作（动态规划+二分查找）](https://michael.blog.csdn.net/article/details/111873879) |                                                              |
| [LeetCode 1236. 网络爬虫（BFS/DFS）](https://michael.blog.csdn.net/article/details/107532151) |                                                              |
| [LeetCode 1237. 找出给定方程的正整数解](https://michael.blog.csdn.net/article/details/103256534) |                                                              |
| [LeetCode 1238. 循环码排列（格雷编码+旋转数组）](https://michael.blog.csdn.net/article/details/105895929) |                                                              |
| [LeetCode 1239. 串联字符串的最大长度（回溯/动态规划）](https://michael.blog.csdn.net/article/details/106297584) |                                                              |
| [LeetCode 1243. 数组变换](https://blog.csdn.net/qq_21201267/article/details/107097416) |                                                              |
| [LeetCode 1244. 力扣排行榜（map+multiset）](https://blog.csdn.net/qq_21201267/article/details/107203159) |                                                              |
| [LeetCode 1245. 树的直径（图的最大直径结论）](https://blog.csdn.net/qq_21201267/article/details/107147225) |                                                              |
| [LeetCode 1246. 删除回文子数组（区间DP）](https://blog.csdn.net/qq_21201267/article/details/107142794) |                                                              |
| [LeetCode 1247. 交换字符使得字符串相同](https://michael.blog.csdn.net/article/details/103561781) |                                                              |
| [LeetCode 1248. 统计「优美子数组」（要复习）](https://michael.blog.csdn.net/article/details/105648303) |                                                              |
| [LeetCode 1249. 移除无效的括号（栈+set / deque）](https://michael.blog.csdn.net/article/details/105793246) |                                                              |
| [LeetCode 1250. 检查「好数组」(set / 最大公约数)](https://michael.blog.csdn.net/article/details/108960785) |                                                              |
| [LeetCode 1252. 奇数值单元格的数目](https://michael.blog.csdn.net/article/details/103133482) |                                                              |
| [LeetCode 1253. 重构 2 行二进制矩阵（贪心）](https://michael.blog.csdn.net/article/details/103319764) |                                                              |
| [LeetCode 1254. 统计封闭岛屿的数目（图的BFS & DFS）](https://michael.blog.csdn.net/article/details/103231347) |                                                              |
| [LeetCode 1255. 得分最高的单词集合（回溯）](https://michael.blog.csdn.net/article/details/106826585) |                                                              |
| [LeetCode 1256. 加密数字（bitset）](https://blog.csdn.net/qq_21201267/article/details/107125994) |                                                              |
| [LeetCode 1257. 最小公共区域（最小公共祖先）](https://michael.blog.csdn.net/article/details/107642952) |                                                              |
| [LeetCode 1258. 近义词句子（哈希+并查集+排序+回溯）](https://michael.blog.csdn.net/article/details/107874963) |                                                              |
| [LeetCode 1260. 二维网格迁移（二维转一维）](https://michael.blog.csdn.net/article/details/103152794) |                                                              |
| [LeetCode 1261. 在受污染的二叉树中查找元素（树&哈希）](https://michael.blog.csdn.net/article/details/103213501) |                                                              |
| [LeetCode 1262. 可被三整除的最大和（DP）](https://michael.blog.csdn.net/article/details/103319572) |                                                              |
| [LeetCode 1263. 推箱子（BFS+DFS / 自定义哈希set）](https://michael.blog.csdn.net/article/details/112055150) |                                                              |
| [LeetCode 1265. 逆序打印不可变链表（递归）](https://blog.csdn.net/qq_21201267/article/details/107109928) |                                                              |
| [LeetCode 1266. 访问所有点的最小时间（数学）](https://michael.blog.csdn.net/article/details/103280533) |                                                              |
| [LeetCode 1267. 统计参与通信的服务器（计数）](https://michael.blog.csdn.net/article/details/106362033) |                                                              |
| [LeetCode 1268. 搜索推荐系统（Trie树/multiset）](https://michael.blog.csdn.net/article/details/106585612) |                                                              |
| [LeetCode 1269. 停在原地的方案数（DP）](https://michael.blog.csdn.net/article/details/116735477) |                                                              |
| [LeetCode 1271. 十六进制魔术数字（进制转换）](https://michael.blog.csdn.net/article/details/103346339) |                                                              |
| [LeetCode 1272. 删除区间](https://michael.blog.csdn.net/article/details/107575663) |                                                              |
| [LeetCode 1273. 删除树节点（拓扑排序/DFS）](https://blog.csdn.net/qq_21201267/article/details/107145802) |                                                              |
| [LeetCode 1274. 矩形内船只的数目（分治）](https://michael.blog.csdn.net/article/details/107780392) |                                                              |
| [LeetCode 1275. 找出井字棋的获胜者（位运算）](https://michael.blog.csdn.net/article/details/103345978) |                                                              |
| [LeetCode 1276. 不浪费原料的汉堡制作方案（解方程）](https://michael.blog.csdn.net/article/details/106388487) |                                                              |
| [LeetCode 1277. 统计全为 1 的正方形子矩阵（DP）](https://michael.blog.csdn.net/article/details/105588317) |                                                              |
| [LeetCode 1278. 分割回文串 III（区间DP）](https://michael.blog.csdn.net/article/details/111935195) |                                                              |
| [LeetCode 1281. 整数的各位积和之差](https://michael.blog.csdn.net/article/details/105594317) |                                                              |
| [LeetCode 1282. 用户分组（桶排序思想）](https://michael.blog.csdn.net/article/details/103483462) |                                                              |
| [LeetCode 1283. 使结果不超过阈值的最小除数（二分查找）](https://michael.blog.csdn.net/article/details/106591523) |                                                              |
| [LeetCode 1284. 转化为全零矩阵的最少反转次数（BFS & 矩阵状态编码解码）](https://michael.blog.csdn.net/article/details/104116933) |                                                              |
| [LeetCode 1286. 字母组合迭代器（回溯/位运算）](https://michael.blog.csdn.net/article/details/105975552) |                                                              |
| [LeetCode 1287. 有序数组中出现次数超过25%的元素](https://michael.blog.csdn.net/article/details/105801573) |                                                              |
| [LeetCode 1288. 删除被覆盖区间（lambda排序）](https://michael.blog.csdn.net/article/details/103916976) |                                                              |
| [LeetCode 1289. 下降路径最小和 II（DP）](https://michael.blog.csdn.net/article/details/104114823) |                                                              |
| [LeetCode 1290. 二进制链表转整数](https://michael.blog.csdn.net/article/details/105594520) |                                                              |
| [LeetCode 1291. 顺次数（模拟）](https://michael.blog.csdn.net/article/details/106578059) |                                                              |
| [LeetCode 1292. 元素和小于等于阈值的正方形的最大边长（DP）](https://michael.blog.csdn.net/article/details/106854305) |                                                              |
| [LeetCode 1293. 网格中的最短路径（DP/BFS）](https://michael.blog.csdn.net/article/details/106981377) |                                                              |
| [LeetCode 1295. 统计位数为偶数的数字](https://michael.blog.csdn.net/article/details/105801508) |                                                              |
| [LeetCode 1296. 划分数组为连续数字的集合（map模拟）](https://michael.blog.csdn.net/article/details/106577446) |                                                              |
| [LeetCode 1297. 子串的最大出现次数](https://michael.blog.csdn.net/article/details/106390406) |                                                              |
| [LeetCode 1298. 你能从盒子里获得的最大糖果数（BFS）](https://michael.blog.csdn.net/article/details/109007617) |                                                              |
| [LeetCode 1299. 将每个元素替换为右侧最大元素](https://michael.blog.csdn.net/article/details/103757611#LeetCode_1299__easy_7) |                                                              |
| [LeetCode 1300. 转变数组后最接近目标值的数组和（二分查找）](https://michael.blog.csdn.net/article/details/105868275) |                                                              |
| [LeetCode 1301. 最大得分的路径数目](https://michael.blog.csdn.net/article/details/103757611#LeetCode_1301__hard_76) |                                                              |
| [LeetCode 1302. 层数最深叶子节点的和](https://michael.blog.csdn.net/article/details/103757611#LeetCode_1302__medium_38) |                                                              |
| [LeetCode 1304. 和为零的N个唯一整数](https://michael.blog.csdn.net/article/details/105801435) |                                                              |
| [LeetCode 1305. 两棵二叉搜索树中的所有元素（二叉树迭代器）](https://michael.blog.csdn.net/article/details/103773511) |                                                              |
| [LeetCode 1306. 跳跃游戏 III（广度优先搜索BFS）](https://michael.blog.csdn.net/article/details/105955995) |                                                              |
| [LeetCode 1309. 解码字母到整数映射](https://michael.blog.csdn.net/article/details/105801288) |                                                              |
| [LeetCode 1310. 子数组异或查询（前缀异或）](https://michael.blog.csdn.net/article/details/105589811) |                                                              |
| [LeetCode 1311. 获取你好友已观看的视频（BFS+哈希map+vector排序）](https://michael.blog.csdn.net/article/details/106086025) |                                                              |
| [LeetCode 1312. 让字符串成为回文串的最少插入次数（区间DP）](https://michael.blog.csdn.net/article/details/108926717) |                                                              |
| [LeetCode 1313. 解压缩编码列表](https://michael.blog.csdn.net/article/details/103942178#LeetCode_5143__easy_7) |                                                              |
| [LeetCode 1314. 矩阵区域和](https://michael.blog.csdn.net/article/details/103942178#LeetCode_5144__medium_44) |                                                              |
| [LeetCode 1315. 祖父节点值为偶数的节点和](https://michael.blog.csdn.net/article/details/103942178#LeetCode_5145__medium_118) |                                                              |
| [LeetCode 1316. 不同的循环子字符串](https://michael.blog.csdn.net/article/details/103942178#LeetCode_5146__hard_177) |                                                              |
| [LeetCode 1317. 将整数转换为两个无零整数的和](https://michael.blog.csdn.net/article/details/103949611) |                                                              |
| [LeetCode 1318. 或运算的最小翻转次数（位运算）](https://michael.blog.csdn.net/article/details/105888872) |                                                              |
| [LeetCode 1319. 连通网络的操作次数（BFS/DFS/并查集）](https://michael.blog.csdn.net/article/details/106087256) |                                                              |
| [LeetCode 1320. 二指输入的的最小距离（动态规划）](https://michael.blog.csdn.net/article/details/109068475) |                                                              |
| [LeetCode 1323. 6 和 9 组成的最大数字](https://michael.blog.csdn.net/article/details/104057397) |                                                              |
| [LeetCode 1324. 竖直打印单词](https://michael.blog.csdn.net/article/details/106007087) |                                                              |
| [LeetCode 1325. 删除给定值的叶子节点（递归）](https://michael.blog.csdn.net/article/details/105546735) |                                                              |
| [LeetCode 1328. 破坏回文串](https://michael.blog.csdn.net/article/details/104087738#LeetCode_1328__medium_65) |                                                              |
| [LeetCode 1329. 将矩阵按对角线排序](https://michael.blog.csdn.net/article/details/104087738#LeetCode_1329__medium_122) |                                                              |
| [LeetCode 1330. 翻转子数组得到最大的数组值](https://michael.blog.csdn.net/article/details/104087738#LeetCode_1330__hard_193) |                                                              |
| [LeetCode 1331. 数组序号转换](https://michael.blog.csdn.net/article/details/104087738#LeetCode_1331__easy_8) |                                                              |
| [LeetCode 1332. 删除回文子序列](https://michael.blog.csdn.net/article/details/104103665) |                                                              |
| [LeetCode 1333. 餐厅过滤器（Lambda排序）](https://michael.blog.csdn.net/article/details/104103801) |                                                              |
| [LeetCode 1334. 阈值距离内邻居最少的城市（最短路径Dijkstra）](https://michael.blog.csdn.net/article/details/104108422) |                                                              |
| [LeetCode 1335. 工作计划的最低难度（DP）](https://michael.blog.csdn.net/article/details/104111153) |                                                              |
| [LeetCode 1337. 方阵中战斗力最弱的 K 行（优先队列）](https://blog.csdn.net/qq_21201267/article/details/104144327) |                                                              |
| [LeetCode 1338. 数组大小减半](https://blog.csdn.net/qq_21201267/article/details/104144925) |                                                              |
| [LeetCode 1339. 分裂二叉树的最大乘积（DP）](https://michael.blog.csdn.net/article/details/104145762) |                                                              |
| [LeetCode 1340. 跳跃游戏 V（DP）](https://michael.blog.csdn.net/article/details/104149099) |                                                              |
| [LeetCode 1342. 将数字变成 0 的操作次数](https://michael.blog.csdn.net/article/details/104230340#LeetCode_5311__0__easy_9) |                                                              |
| [LeetCode 1343. 大小为 K 且平均值大于等于阈值的子数组数目（双指针）](https://michael.blog.csdn.net/article/details/104230340#LeetCode_5312__K__medium_69) |                                                              |
| [LeetCode 1344. 时钟指针的夹角](https://michael.blog.csdn.net/article/details/104230340#LeetCode_5313__medium_139) |                                                              |
| [LeetCode 1345. 跳跃游戏 IV （BFS 最短路径）](https://michael.blog.csdn.net/article/details/104230340#LeetCode_5314__IV_hard_168) |                                                              |
| [LeetCode 1346. 检查整数及其两倍数是否存在（哈希）](https://michael.blog.csdn.net/article/details/104234658) |                                                              |
| [LeetCode 1347. 制造字母异位词的最小步骤数](https://michael.blog.csdn.net/article/details/104239038) |                                                              |
| [LeetCode 1348. 推文计数（哈希map+set）](https://michael.blog.csdn.net/article/details/104242072) |                                                              |
| [LeetCode 1351. 统计有序矩阵中的负数](https://michael.blog.csdn.net/article/details/104342220) |                                                              |
| [LeetCode 1352. 最后 K 个数的乘积](https://michael.blog.csdn.net/article/details/104342755) |                                                              |
| [LeetCode 1353. 最多可以参加的会议数目（排序+贪心，优先队列，难）](https://michael.blog.csdn.net/article/details/104344969) |                                                              |
| [LeetCode 1354. 多次求和构造目标数组（优先队列+逆向思考）](https://michael.blog.csdn.net/article/details/104351025) |                                                              |
| [LeetCode 1356. 根据数字二进制下 1 的数目排序（自定义lambda排序）](https://michael.blog.csdn.net/article/details/104453219#LeetCode_5323__1__easy_18) |                                                              |
| [LeetCode 1357. 每隔 n 个顾客打折（哈希）](https://michael.blog.csdn.net/article/details/104453219#LeetCode_5324__n__medium_90) |                                                              |
| [LeetCode 1358. 包含所有三种字符的子字符串数目（二分查找）](https://michael.blog.csdn.net/article/details/104453219#LeetCode_5325__medium_195) |                                                              |
| [LeetCode 1359. 有效的快递序列数目（动态规划）](https://michael.blog.csdn.net/article/details/104453219#LeetCode_5326__hard_307) |                                                              |
| [LeetCode 1360. 日期之间隔几天（闰年判断）](https://michael.blog.csdn.net/article/details/104462662) |                                                              |
| [LeetCode 1361. 验证二叉树（图的出入度）](https://michael.blog.csdn.net/article/details/104465277) |                                                              |
| [LeetCode 1362. 最接近的因数](https://michael.blog.csdn.net/article/details/104466518) |                                                              |
| [LeetCode 1363. 形成三的最大倍数（贪心，难）](https://michael.blog.csdn.net/article/details/104468904) |                                                              |
| [LeetCode 1365. 有多少小于当前数字的数字（排序）](https://michael.blog.csdn.net/article/details/104590855) |                                                              |
| [LeetCode 1366. 通过投票对团队排名（自定义排序）](https://michael.blog.csdn.net/article/details/104593866) |                                                              |
| [LeetCode 1367. 二叉树中的列表（双重递归）](https://michael.blog.csdn.net/article/details/104596571) |                                                              |
| [LeetCode 1368. 使网格图至少有一条有效路径的最小代价（BFS最短路径，难）](https://michael.blog.csdn.net/article/details/104598714) |                                                              |
| [LeetCode 1370. 上升下降字符串](https://michael.blog.csdn.net/article/details/104725634#LeetCode_5336__easy_8) |                                                              |
| [LeetCode 1371. 每个元音包含偶数次的最长子字符串（异或前缀值）](https://michael.blog.csdn.net/article/details/104725634#LeetCode_5337__medium_99) |                                                              |
| [LeetCode 1372. 二叉树中的最长交错路径（递归，注意不要超时）](https://michael.blog.csdn.net/article/details/104725634#LeetCode_5338__medium_174) |                                                              |
| [LeetCode 1373. 二叉搜索子树的最大键值和（自底向上DP，返回vector多变量）](https://michael.blog.csdn.net/article/details/104725634#LeetCode_5339__hard_264) |                                                              |
| [LeetCode 1374. 生成每种字符都是奇数个的字符串](https://michael.blog.csdn.net/article/details/104738254) |                                                              |
| [LeetCode 1375. 灯泡开关 III](https://michael.blog.csdn.net/article/details/104740515) |                                                              |
| [LeetCode 1376. 通知所有员工所需的时间（DFS）](https://michael.blog.csdn.net/article/details/104737998) |                                                              |
| [LeetCode 1377. T 秒后青蛙的位置（BFS）](https://michael.blog.csdn.net/article/details/104737728) |                                                              |
| [LeetCode 1379. 找出克隆二叉树中的相同节点（二叉树遍历）](https://michael.blog.csdn.net/article/details/105479474) |                                                              |
| [LeetCode 1380. 矩阵中的幸运数（set）](https://michael.blog.csdn.net/article/details/104878993) |                                                              |
| [LeetCode 1381. 设计一个支持增量操作的栈（deque/数组）](https://michael.blog.csdn.net/article/details/104879528) |                                                              |
| [LeetCode 1382. 将二叉搜索树变平衡（中序遍历+二分递归）](https://michael.blog.csdn.net/article/details/104879123) |                                                              |
| [LeetCode 1383. 最大的团队表现值（贪心，优先队列，难）](https://michael.blog.csdn.net/article/details/104882484) |                                                              |
| [LeetCode 1385. 两个数组间的距离值](https://blog.csdn.net/qq_21201267/article/details/105022135#LeetCode_5348__easy_9) |                                                              |
| [LeetCode 1386. 安排电影院座位（map+bitset）](https://blog.csdn.net/qq_21201267/article/details/105022135#LeetCode_5349__medium_85) |                                                              |
| [LeetCode 1387. 将整数按权重排序（自定义排序）](https://blog.csdn.net/qq_21201267/article/details/105022135#LeetCode_5350__medium_192) |                                                              |
| [LeetCode 1388. 3n 块披萨 hard（动态规划）](https://blog.csdn.net/qq_21201267/article/details/105022135#LeetCode_5351_3n__hard_281) |                                                              |
| [LeetCode 1389. 按既定顺序创建目标数组](https://blog.csdn.net/qq_21201267/article/details/105033366) |                                                              |
| [LeetCode 1390. 四因数](https://blog.csdn.net/qq_21201267/article/details/105033772) |                                                              |
| [LeetCode 1391. 检查网格中是否存在有效路径（BFS）](https://michael.blog.csdn.net/article/details/105038964) |                                                              |
| [LeetCode 1392. 最长快乐前缀（KMP）](https://michael.blog.csdn.net/article/details/105039592) |                                                              |
| [LeetCode 1394. 找出数组中的幸运数（map计数）](https://blog.csdn.net/qq_21201267/article/details/105176371) |                                                              |
| [LeetCode 1395. 统计作战单位数（蛮力法）](https://blog.csdn.net/qq_21201267/article/details/105176543) |                                                              |
| [LeetCode 1396. 设计地铁系统（map/unordered_map）](https://blog.csdn.net/qq_21201267/article/details/105178882) |                                                              |
| [LeetCode 1399. 统计最大组的数目](https://michael.blog.csdn.net/article/details/105323119#1_LeetCode_5360__easy_11) |                                                              |
| [LeetCode 1400. 构造 K 个回文字符串（脑洞题）](https://michael.blog.csdn.net/article/details/105323119#2_LeetCode_5362__K__medium_83) |                                                              |
| [LeetCode 1401. 圆和矩形是否有重叠（数学）](https://michael.blog.csdn.net/article/details/105323119#3_LeetCode_5361__medium_149) |                                                              |
| [LeetCode 1402. 做菜顺序（贪心+动态规划）](https://michael.blog.csdn.net/article/details/105323119#4_LeetCode_5363__hard_207) |                                                              |
| [LeetCode 1403. 非递增顺序的最小子序列（排序）](https://michael.blog.csdn.net/article/details/105327168) |                                                              |
| [LeetCode 1404. 将二进制表示减到 1 的步骤数（字符串加法）](https://michael.blog.csdn.net/article/details/105327882) |                                                              |
| [LeetCode 1405. 最长快乐字符串（贪心）](https://blog.csdn.net/qq_21201267/article/details/105330626) |                                                              |
| [LeetCode 1406. 石子游戏 III（DP）](https://blog.csdn.net/qq_21201267/article/details/105332878) |                                                              |
| [LeetCode 1408. 数组中的字符串匹配（暴力查找）](https://michael.blog.csdn.net/article/details/105474377) |                                                              |
| [LeetCode 1409. 查询带键的排列（map模拟）](https://michael.blog.csdn.net/article/details/105476278) |                                                              |
| [LeetCode 1410. HTML 实体解析器（哈希map）](https://michael.blog.csdn.net/article/details/105478099) |                                                              |
| [LeetCode 1411. 给 N x 3 网格图涂色的方案数（数学）](https://michael.blog.csdn.net/article/details/105478846) |                                                              |
| [LeetCode 1413. 逐步求和得到正数的最小值](https://michael.blog.csdn.net/article/details/105608345#1_LeetCode_5372__easy_10) |                                                              |
| [LeetCode 1414. 和为 K 的最少斐波那契数字数目（set二分查找+贪心）](https://michael.blog.csdn.net/article/details/105608345#2_LeetCode_5373__K__medium_69) |                                                              |
| [LeetCode 1415. 长度为 n 的开心字符串中字典序第 k 小的字符串（DFS）](https://michael.blog.csdn.net/article/details/105608345#3_LeetCode_5374__n__k__medium_135) |                                                              |
| [LeetCode 1417. 重新格式化字符串](https://michael.blog.csdn.net/article/details/105613930) |                                                              |
| [LeetCode 1418. 点菜展示表（哈希map）](https://michael.blog.csdn.net/article/details/105615677) |                                                              |
| [LeetCode 1419. 数青蛙（脑洞题）](https://michael.blog.csdn.net/article/details/105618418) |                                                              |
| [LeetCode 1422. 分割字符串的最大得分（前缀和）](https://michael.blog.csdn.net/article/details/105766947#1_LeetCode_5392__easy_9) |                                                              |
| [LeetCode 1423. 可获得的最大点数（前缀和）](https://michael.blog.csdn.net/article/details/105766947#2_LeetCode_5393__medium_98) |                                                              |
| [LeetCode 1424. 对角线遍历 II（哈希分组+排序）](https://michael.blog.csdn.net/article/details/105766947#3_LeetCode_5394__II_medium_169) |                                                              |
| [LeetCode 1425. 带限制的子序列和（DP+单调栈）](https://michael.blog.csdn.net/article/details/105766947#4_LeetCode_5180__hard_322) |                                                              |
| [LeetCode 1426. 数元素（哈希set）](https://blog.csdn.net/qq_21201267/article/details/107096367) |                                                              |
| [LeetCode 1427. 字符串的左右移](https://blog.csdn.net/qq_21201267/article/details/107095564) |                                                              |
| [LeetCode 1428. 至少有一个 1 的最左端列（二分查找）](https://blog.csdn.net/qq_21201267/article/details/107125054) |                                                              |
| [LeetCode 1429. 第一个唯一数字（map+queue）](https://blog.csdn.net/qq_21201267/article/details/107197994) |                                                              |
| [LeetCode 1430. 判断给定的序列是否是二叉树从根到叶的路径（递归）](https://blog.csdn.net/qq_21201267/article/details/107117712) |                                                              |
| [LeetCode 1431. 拥有最多糖果的孩子](https://michael.blog.csdn.net/article/details/105897792#1_LeetCode_5384__easy_11) |                                                              |
| [LeetCode 1432. 改变一个整数能得到的最大差值](https://michael.blog.csdn.net/article/details/105897792#2_LeetCode_5385__medium_91) |                                                              |
| [LeetCode 1433. 检查一个字符串是否可以打破另一个字符串（排序）](https://michael.blog.csdn.net/article/details/105897792#3_LeetCode_5386__medium_201) |                                                              |
| [LeetCode 1434. 每个人戴不同帽子的方案数（状态压缩+DP）](https://michael.blog.csdn.net/article/details/105897792#4_LeetCode_5387__hard_265) |                                                              |
| [LeetCode 1436. 旅行终点站（图的出入度）](https://michael.blog.csdn.net/article/details/105903207#1_LeetCode_5400__easy_11) |                                                              |
| [LeetCode 1437. 是否所有 1 都至少相隔 k 个元素](https://michael.blog.csdn.net/article/details/105903207#2_LeetCode_5401__1__k__medium_99) |                                                              |
| [LeetCode 1438. 绝对差不超过限制的最长连续子数组（滑动窗口+map）](https://michael.blog.csdn.net/article/details/105903207#3_LeetCode_5402__medium_187) |                                                              |
| [LeetCode 1439. 有序矩阵中的第 k 个最小数组和（优先队列+DP）](https://michael.blog.csdn.net/article/details/105903207#4_LeetCode_5403__k__hard_295) |                                                              |
| [LeetCode 1441. 用栈操作构建数组](https://michael.blog.csdn.net/article/details/106035352) |                                                              |
| [LeetCode 1442. 形成两个异或相等数组的三元组数目（前缀异或）](https://michael.blog.csdn.net/article/details/106035610) |                                                              |
| [LeetCode 1443. 收集树上所有苹果的最少时间（自底向上DFS）](https://michael.blog.csdn.net/article/details/106037189) |                                                              |
| [LeetCode 1444. 切披萨的方案数（DP）](https://michael.blog.csdn.net/article/details/106729347) |                                                              |
| [LeetCode 1446. 连续字符](https://michael.blog.csdn.net/article/details/106167968#1_LeetCode_5396__easy_11) |                                                              |
| [LeetCode 1447. 最简分数（公约数为1）](https://michael.blog.csdn.net/article/details/106167968#2_LeetCode_5397__medium_69) |                                                              |
| [LeetCode 1448. 统计二叉树中好节点的数目（递归）](https://michael.blog.csdn.net/article/details/106167968#3_LeetCode_5398__medium_137) |                                                              |
| [LeetCode 1449. 数位成本和为目标值的最大数字（DP）](https://michael.blog.csdn.net/article/details/117850581) |                                                              |
| [LeetCode 1450. 在既定时间做作业的学生人数](https://michael.blog.csdn.net/article/details/106172689) |                                                              |
| [LeetCode 1451. 重新排列句子中的单词（桶排序）](https://michael.blog.csdn.net/article/details/106172985) |                                                              |
| [LeetCode 1452. 收藏清单（std::includes判断子集）](https://michael.blog.csdn.net/article/details/106174067) |                                                              |
| [LeetCode 1453. 圆形靶内的最大飞镖数量（几何题）](https://michael.blog.csdn.net/article/details/106177445) |                                                              |
| [LeetCode 1455. 检查单词是否为句中其他单词的前缀](https://michael.blog.csdn.net/article/details/106313448) |                                                              |
| [LeetCode 1456. 定长子串中元音的最大数目（滑动窗口）](https://michael.blog.csdn.net/article/details/106313584) |                                                              |
| [LeetCode 1457. 二叉树中的伪回文路径（位运算+递归）](https://michael.blog.csdn.net/article/details/106314008) |                                                              |
| [LeetCode 1458. 两个子序列的最大点积（动态规划，类似编辑距离）](https://michael.blog.csdn.net/article/details/106314729) |                                                              |
| [LeetCode 1460. 通过翻转子数组使两个数组相等](https://michael.blog.csdn.net/article/details/106453232#1_LeetCode_5408__easy_11) |                                                              |
| [LeetCode 1461. 检查一个字符串是否包含所有长度为 K 的二进制子串（滑动窗口）](https://michael.blog.csdn.net/article/details/106453232#2_LeetCode_5409__K__medium_72) |                                                              |
| [LeetCode 1462. 课程安排 IV（Floyd-Warshall弗洛伊德最短路径）](https://michael.blog.csdn.net/article/details/106453232#3_LeetCode_5410__IV_medium_FloydWarshall_171) |                                                              |
| [LeetCode 1463. 摘樱桃 II （DP）](https://michael.blog.csdn.net/article/details/106453232#4_LeetCode_5411__II_hard_282) |                                                              |
| [LeetCode 1464. 数组中两元素的最大乘积](https://michael.blog.csdn.net/article/details/106459471) |                                                              |
| [LeetCode 1465. 切割后面积最大的蛋糕](https://michael.blog.csdn.net/article/details/106459741) |                                                              |
| [LeetCode 1466. 重新规划路线（DFS/BFS）](https://michael.blog.csdn.net/article/details/106461424) |                                                              |
| [LeetCode 1469. 寻找所有的独生节点](https://blog.csdn.net/qq_21201267/article/details/107093216) |                                                              |
| [LeetCode 1470. 重新排列数组](https://michael.blog.csdn.net/article/details/106600292) |                                                              |
| [LeetCode 1471. 数组中的 k 个最强值（排序）](https://michael.blog.csdn.net/article/details/106600636) |                                                              |
| [LeetCode 1472. 设计浏览器历史记录（双栈）](https://michael.blog.csdn.net/article/details/106601089) |                                                              |
| [LeetCode 1473. 给房子涂色 III（DP）](https://michael.blog.csdn.net/article/details/106606529) |                                                              |
| [LeetCode 1474. 删除链表 M 个节点之后的 N 个节点](https://blog.csdn.net/qq_21201267/article/details/107095319) |                                                              |
| [LeetCode 1475. 商品折扣后的最终价格（单调栈）](https://michael.blog.csdn.net/article/details/106736232#1_LeetCode_5420__easy_13) |                                                              |
| [LeetCode 1476. 子矩形查询](https://michael.blog.csdn.net/article/details/106736232#2_LeetCode_5422__medium_110) |                                                              |
| [LeetCode 1477. 找两个和为目标值且不重叠的子数组（滑动窗口/正反前缀和）](https://michael.blog.csdn.net/article/details/106736232#3_LeetCode_5423__medium_248) |                                                              |
| [LeetCode 1480. 一维数组的动态和（前缀和）](https://michael.blog.csdn.net/article/details/106748641) |                                                              |
| [LeetCode 1481. 不同整数的最少数目（计数+排序+贪心）](https://michael.blog.csdn.net/article/details/106748963) |                                                              |
| [LeetCode 1482. 制作 m 束花所需的最少天数（二分查找）](https://michael.blog.csdn.net/article/details/106749930) |                                                              |
| [LeetCode 1484. 克隆含随机指针的二叉树（哈希/递归）](https://michael.blog.csdn.net/article/details/107570532) |                                                              |
| [LeetCode 1486. 数组异或操作](https://michael.blog.csdn.net/article/details/106883899) |                                                              |
| [LeetCode 1487. 保证文件名唯一（哈希map）](https://michael.blog.csdn.net/article/details/106884295) |                                                              |
| [LeetCode 1488. 避免洪水泛滥（哈希map+deque）](https://michael.blog.csdn.net/article/details/106889436) |                                                              |
| [LeetCode 1489. 找到最小生成树里的关键边和伪关键边（并查集+kruskal最小生成树）](https://michael.blog.csdn.net/article/details/112919914) |                                                              |
| [LeetCode 1490. 克隆 N 叉树（DFS/BFS）](https://blog.csdn.net/qq_21201267/article/details/107110691) |                                                              |
| [LeetCode 1491. 去掉最低工资和最高工资后的工资平均值](https://michael.blog.csdn.net/article/details/106990467#1_LeetCode_5432__easy_13) |                                                              |
| [LeetCode 1492. n 的第 k 个因子](https://michael.blog.csdn.net/article/details/106990467#2_LeetCode_5433_n__k__medium_75) |                                                              |
| [LeetCode 1493. 删掉一个元素以后全为 1 的最长子数组（滑动窗口）](https://michael.blog.csdn.net/article/details/106990467#3_LeetCode_5434__1__medium_175) |                                                              |
| [LeetCode 1496. 判断路径是否相交（set）](https://michael.blog.csdn.net/article/details/106996303) |                                                              |
| [LeetCode 1497. 检查数组对是否可以被 k 整除（余数配对）](https://michael.blog.csdn.net/article/details/106996448) |                                                              |
| [LeetCode 1498. 满足条件的子序列数目（排序+二分查找+快速幂）](https://michael.blog.csdn.net/article/details/106996638) |                                                              |
| [LeetCode 1500. Design a File Sharing System（哈希map+优先队列）](https://michael.blog.csdn.net/article/details/107620952) |                                                              |
| [LeetCode 1502. 判断能否形成等差数列](https://blog.csdn.net/qq_21201267/article/details/107137163) |                                                              |
| [LeetCode 1503. 所有蚂蚁掉下来前的最后一刻（脑筋急转弯）](https://blog.csdn.net/qq_21201267/article/details/107141312) |                                                              |
| [LeetCode 1504. 统计全 1 子矩形（记录左侧的连续1的个数）](https://blog.csdn.net/qq_21201267/article/details/107139936) |                                                              |
| [LeetCode 1506. Find Root of N-Ary Tree（异或）](https://michael.blog.csdn.net/article/details/107380727) |                                                              |
| [LeetCode 1507. 转变日期格式](https://michael.blog.csdn.net/article/details/107293199#1_LeetCode_5177__easy_15) |                                                              |
| [LeetCode 1508. 子数组和排序后的区间和](https://michael.blog.csdn.net/article/details/107293199#2_LeetCode_5445__medium_90) |                                                              |
| [LeetCode 1509. 三次操作后最大值与最小值的最小差](https://michael.blog.csdn.net/article/details/107293199#3_LeetCode_5446__medium_164) |                                                              |
| [LeetCode 1510. 石子游戏 IV（博弈DP）](https://michael.blog.csdn.net/article/details/107293199#4_LeetCode_5447__IV_hardDP_217) |                                                              |
| [LeetCode 1512. 好数对的数目](https://michael.blog.csdn.net/article/details/107297636#1_LeetCode_5460__easy_13) |                                                              |
| [LeetCode 1513. 仅含 1 的子串数](https://michael.blog.csdn.net/article/details/107297636#2_LeetCode_5461__1__medium_66) |                                                              |
| [LeetCode 1514. 概率最大的路径（Dijkstra+优先队列优化）](https://michael.blog.csdn.net/article/details/107297636#3_LeetCode_5211__medium_135) |                                                              |
| [LeetCode 1515. 服务中心的最佳位置（最优化退火迭代）](https://michael.blog.csdn.net/article/details/107297636#4_LeetCode_5463__hard_239) |                                                              |
| [LeetCode 1516. Move Sub-Tree of N-Ary Tree（DFS）](https://michael.blog.csdn.net/article/details/107420745) |                                                              |
| [LeetCode 1518. 换酒问题](https://michael.blog.csdn.net/article/details/107443611#1_LeetCode_5464__easy_15) |                                                              |
| [LeetCode 1519. 子树中标签相同的节点数（DFS）](https://michael.blog.csdn.net/article/details/107443611#2_LeetCode_5465__medium_91) |                                                              |
| [LeetCode 1520. 最多的不重叠子字符串（贪心）](https://michael.blog.csdn.net/article/details/108152559) |                                                              |
| [LeetCode 1521. 找到最接近目标值的函数值（位运算）](https://michael.blog.csdn.net/article/details/121054974) |                                                              |
| [LeetCode 1522. Diameter of N-Ary Tree（递归）](https://michael.blog.csdn.net/article/details/107552746) |                                                              |
| [LeetCode 1523. 在区间范围内统计奇数数目](https://editor.csdn.net/md/?articleId=107587115#1_LeetCode_5456__easy_14) |                                                              |
| [LeetCode 1524. 和为奇数的子数组数目](https://editor.csdn.net/md/?articleId=107587115#2_LeetCode_5457__medium_67) |                                                              |
| [LeetCode 1525. 字符串的好分割数目（双指针）](https://editor.csdn.net/md/?articleId=107587115#3_LeetCode_5458__medium_137) |                                                              |
| [LeetCode 1526. 形成目标数组的子数组最少增加次数](https://editor.csdn.net/md/?articleId=107587115#4_LeetCode_5459__hard_205) |                                                              |
| [LeetCode 1528. 重新排列字符串](https://michael.blog.csdn.net/article/details/107591466#1_LeetCode_5472__easy_14) |                                                              |
| [LeetCode 1529. 灯泡开关 IV](https://michael.blog.csdn.net/article/details/107591466#2_LeetCode_5473__IV_medium_88) |                                                              |
| [LeetCode 1530. 好叶子节点对的数量（自底向上DFS）](https://michael.blog.csdn.net/article/details/107591466#3_LeetCode_5474__medium_156) |                                                              |
| [LeetCode 1533. Find the Index of the Large Integer（二分查找）](https://michael.blog.csdn.net/article/details/107691850) |                                                              |
| [LeetCode 1534. 统计好三元组](https://michael.blog.csdn.net/article/details/107743199) |                                                              |
| [LeetCode 1535. 找出数组游戏的赢家](https://michael.blog.csdn.net/article/details/107743252) |                                                              |
| [LeetCode 1536. 排布二进制网格的最少交换次数](https://michael.blog.csdn.net/article/details/107743307) |                                                              |
| [LeetCode 1537. 最大得分（切片取出局部最大值）](https://michael.blog.csdn.net/article/details/107743421) |                                                              |
| [LeetCode 1538. Guess the Majority in a Hidden Array](https://michael.blog.csdn.net/article/details/107874237) |                                                              |
| [LeetCode 1539. 第 k 个缺失的正整数](https://michael.blog.csdn.net/article/details/107892779#1_LeetCode_5468__k__easy_15) |                                                              |
| [LeetCode 1540. K 次操作转变字符串（计数）](https://michael.blog.csdn.net/article/details/107892779#2_LeetCode_5469_K__medium_76) |                                                              |
| [LeetCode 1541. 平衡括号字符串的最少插入次数（栈括号匹配）](https://michael.blog.csdn.net/article/details/107892779#3_LeetCode_5470__medium_155) |                                                              |
| [LeetCode 1542. 找出最长的超赞子字符串（状态压缩+哈希）](https://michael.blog.csdn.net/article/details/107892779#4_LeetCode_5485__hard_293) |                                                              |
| [LeetCode 1544. 整理字符串（栈）](https://michael.blog.csdn.net/article/details/107894840#1_LeetCode_5483__easy_15) |                                                              |
| [LeetCode 1545. 找出第 N 个二进制字符串中的第 K 位（递归）](https://michael.blog.csdn.net/article/details/107894840#2_LeetCode_5484__N__K__medium_89) |                                                              |
| [LeetCode 1546. 和为目标值的最大数目不重叠非空子数组数目（哈希）](https://michael.blog.csdn.net/article/details/107894840#3_LeetCode_5471__medium_213) |                                                              |
| [LeetCode 1547. 切棍子的最小成本（区间DP）](https://michael.blog.csdn.net/article/details/107894840#4_LeetCode_5486__hard_276) |                                                              |
| [LeetCode 1548. The Most Similar Path in a Graph（动态规划）](https://michael.blog.csdn.net/article/details/107983113) |                                                              |
| [LeetCode 1550. 存在连续三个奇数的数组](https://michael.blog.csdn.net/article/details/108034781) |                                                              |
| [LeetCode 1551. 使数组中所有元素相等的最小操作数（等差数列）](https://michael.blog.csdn.net/article/details/108034903) |                                                              |
| [LeetCode 1552. 两球之间的磁力（极小极大化 二分查找）](https://michael.blog.csdn.net/article/details/108035117) |                                                              |
| [LeetCode 1553. 吃掉 N 个橘子的最少天数（BFS）](https://michael.blog.csdn.net/article/details/108035625) |                                                              |
| [LeetCode 1554. 只有一个不同字符的字符串（枚举）](https://michael.blog.csdn.net/article/details/119702941) |                                                              |
| [LeetCode 1556. 千位分隔数](https://michael.blog.csdn.net/article/details/108177289#1_LeetCode_5479__easy_15) |                                                              |
| [LeetCode 1557. 可以到达所有点的最少点数目（图的入度）](https://michael.blog.csdn.net/article/details/108177289#2_LeetCode_5480__medium_76) |                                                              |
| [LeetCode 1558. 得到目标数组的最少函数调用次数](https://michael.blog.csdn.net/article/details/108177289#3_LeetCode_5481__medium_146) |                                                              |
| [LeetCode 1559. 二维网格图中探测环（DFS）](https://michael.blog.csdn.net/article/details/108177289#4_LeetCode_5482__hard_234) |                                                              |
| [LeetCode 1560. 圆形赛道上经过次数最多的扇区](https://michael.blog.csdn.net/article/details/108181426) |                                                              |
| [LeetCode 1561. 你可以获得的最大硬币数目](https://michael.blog.csdn.net/article/details/108183189) |                                                              |
| [LeetCode 1562. 查找大小为 M 的最新分组](https://michael.blog.csdn.net/article/details/108183460) |                                                              |
| [LeetCode 1563. 石子游戏 V（DP）](https://michael.blog.csdn.net/article/details/108185564) |                                                              |
| [LeetCode 1564. 把箱子放进仓库里 I（排序）](https://michael.blog.csdn.net/article/details/119713482) |                                                              |
| [LeetCode 1566. 重复至少 K 次且长度为 M 的模式](https://michael.blog.csdn.net/article/details/108306022) |                                                              |
| [LeetCode 1567. 乘积为正数的最长子数组长度](https://michael.blog.csdn.net/article/details/108306529) |                                                              |
| [LeetCode 1568. 使陆地分离的最少天数（DFS）](https://michael.blog.csdn.net/article/details/108307844) |                                                              |
| [LeetCode 1569. 将子数组重新排序得到同一个二叉查找树的方案数（DP）](https://michael.blog.csdn.net/article/details/108309600) |                                                              |
| [LeetCode 1570. 两个稀疏向量的点积（哈希）](https://michael.blog.csdn.net/article/details/119706510) |                                                              |
| [LeetCode 1572. 矩阵对角线元素的和](https://michael.blog.csdn.net/article/details/108426333#1_LeetCode_5491__easy_14) |                                                              |
| [LeetCode 1573. 分割字符串的方案数](https://michael.blog.csdn.net/article/details/108426333#2_LeetCode_5492__medium_76) |                                                              |
| [LeetCode 1574. 删除最短的子数组使剩余数组有序](https://michael.blog.csdn.net/article/details/108426333#3_LeetCode_5493__medium_164) |                                                              |
| [LeetCode 1575. 统计所有可行路径（DP）](https://michael.blog.csdn.net/article/details/108426333#4_LeetCode_5494__hard_254) |                                                              |
| [LeetCode 1576. 替换所有的问号](https://michael.blog.csdn.net/article/details/108430295) |                                                              |
| [LeetCode 1577. 数的平方等于两数乘积的方法数（双指针）](https://michael.blog.csdn.net/article/details/108430344) |                                                              |
| [LeetCode 1578. 避免重复字母的最小删除成本](https://michael.blog.csdn.net/article/details/108430423) |                                                              |
| [LeetCode 1579. 保证图可完全遍历（并查集）](https://michael.blog.csdn.net/article/details/108438962) |                                                              |
| [LeetCode 1580. 把箱子放进仓库里 II（排序）](https://michael.blog.csdn.net/article/details/119714016) |                                                              |
| [LeetCode 1582. 二进制矩阵中的特殊位置](https://michael.blog.csdn.net/article/details/108561122#1_LeetCode_5511__easy_14) |                                                              |
| [LeetCode 1583. 统计不开心的朋友](https://michael.blog.csdn.net/article/details/108561122#2_LeetCode_5512__medium_114) |                                                              |
| [LeetCode 1584. 连接所有点的最小费用（最小生成树）](https://michael.blog.csdn.net/article/details/108561122#3_LeetCode_5513__medium_225) |                                                              |
| [LeetCode 1585. 检查字符串是否可以通过排序子字符串得到另一个字符串（队列）](https://michael.blog.csdn.net/article/details/108561122#4_LeetCode_5514__hard_404) |                                                              |
| [LeetCode 1586. 二叉搜索树迭代器 II（数组+栈）](https://michael.blog.csdn.net/article/details/119706307) |                                                              |
| [LeetCode 1588. 所有奇数长度子数组的和](https://michael.blog.csdn.net/article/details/108688898#1_LeetCode_5503__easy_15) |                                                              |
| [LeetCode 1589. 所有排列中的最大和（差分+前缀和）](https://michael.blog.csdn.net/article/details/108688898#2_LeetCode_5505__medium_117) |                                                              |
| [LeetCode 1590. 使数组和能被 P 整除（哈希+前缀和）](https://michael.blog.csdn.net/article/details/108688898#3_LeetCode_5504__P__medium_199) |                                                              |
| [LeetCode 1592. 重新排列单词间的空格](https://michael.blog.csdn.net/article/details/108691909#1_LeetCode_5519__easy_15) |                                                              |
| [LeetCode 1593. 拆分字符串使唯一子字符串的数目最大（回溯）](https://michael.blog.csdn.net/article/details/108691909#2_LeetCode_5520__medium_108) |                                                              |
| [LeetCode 1594. 矩阵的最大非负积（DP）](https://michael.blog.csdn.net/article/details/108691909#3_LeetCode_5521__medium_223) |                                                              |
| [LeetCode 1598. 文件夹操作日志搜集器](https://michael.blog.csdn.net/article/details/108826605) |                                                              |
| [LeetCode 1599. 经营摩天轮的最大利润（模拟）](https://michael.blog.csdn.net/article/details/108827543) |                                                              |
| [LeetCode 1600. 皇位继承顺序（图的深度优先遍历）](https://michael.blog.csdn.net/article/details/108829683) |                                                              |
| [LeetCode 1601. 最多可达成的换楼请求数目（回溯+剪枝）](https://michael.blog.csdn.net/article/details/108835238) |                                                              |
| [LeetCode 1602. 找到二叉树中最近的右侧节点（BFS）](https://michael.blog.csdn.net/article/details/119714378) |                                                              |
| [LeetCode 1603. 设计停车系统](https://michael.blog.csdn.net/article/details/108914842#1_LeetCode_5515__easy_15) |                                                              |
| [LeetCode 1604. 警告一小时内使用相同员工卡大于等于三次的人（map+set）](https://michael.blog.csdn.net/article/details/108914842#2_LeetCode_5516__medium_89) |                                                              |
| [LeetCode 1605. 给定行和列的和求可行矩阵（贪心）](https://michael.blog.csdn.net/article/details/108914842#3_LeetCode_5518__medium_179) |                                                              |
| [LeetCode 1606. 找到处理最多请求的服务器（优先队列+set）](https://michael.blog.csdn.net/article/details/108914842#4_LeetCode_5517__hard_258) |                                                              |
| [LeetCode 1608. 特殊数组的特征值](https://michael.blog.csdn.net/article/details/108921246) |                                                              |
| [LeetCode 1609. 奇偶树（层序遍历）](https://michael.blog.csdn.net/article/details/108921586) |                                                              |
| [LeetCode 1610. 可见点的最大数目（atan2函数求夹角）](https://michael.blog.csdn.net/article/details/108921772) |                                                              |
| [LeetCode 1614. 括号的最大嵌套深度](https://michael.blog.csdn.net/article/details/109011780) |                                                              |
| [LeetCode 1615. 最大网络秩（出入度）](https://michael.blog.csdn.net/article/details/109012095) |                                                              |
| [LeetCode 1616. 分割两个字符串得到回文串](https://michael.blog.csdn.net/article/details/109012491) |                                                              |
| [LeetCode 1617. 统计子树中城市之间最大距离（枚举所有可能+图的最大直径）](https://michael.blog.csdn.net/article/details/109014936) |                                                              |
| [LeetCode 1618. 找出适应屏幕的最大字号（二分查找）](https://michael.blog.csdn.net/article/details/119709520) |                                                              |
| [LeetCode 1619. 删除某些元素后的数组均值](https://michael.blog.csdn.net/article/details/109143348) |                                                              |
| [LeetCode 1620. 网络信号最好的坐标](https://michael.blog.csdn.net/article/details/109143371) |                                                              |
| [LeetCode 1624. 两个相同字符之间的最长子字符串](https://michael.blog.csdn.net/article/details/109143817) |                                                              |
| [LeetCode 1625. 执行操作后字典序最小的字符串（BFS）](https://michael.blog.csdn.net/article/details/109144840) |                                                              |
| [LeetCode 1626. 无矛盾的最佳球队（最大上升子序DP）](https://michael.blog.csdn.net/article/details/109147451) |                                                              |
| [LeetCode 1629. 按键持续时间最长的键](https://michael.blog.csdn.net/article/details/109273024) |                                                              |
| [LeetCode 1630. 等差子数组](https://michael.blog.csdn.net/article/details/109273589) |                                                              |
| [LeetCode 1631. 最小体力消耗路径（DFS + 二分查找）](https://michael.blog.csdn.net/article/details/109274216) |                                                              |
| [LeetCode 1634. 求两个多项式链表的和](https://michael.blog.csdn.net/article/details/119709934) |                                                              |
| [LeetCode 1636. 按照频率将数组升序排序（哈希+排序）](https://michael.blog.csdn.net/article/details/109432416) |                                                              |
| [LeetCode 1637. 两点之间不包含任何点的最宽垂直面积](https://michael.blog.csdn.net/article/details/109432554) |                                                              |
| [LeetCode 1638. 统计只差一个字符的子串数目（DP）](https://michael.blog.csdn.net/article/details/109433008) |                                                              |
| [LeetCode 1640. 能否连接形成数组（哈希）](https://michael.blog.csdn.net/article/details/109435340) |                                                              |
| [LeetCode 1641. 统计字典序元音字符串的数目（DP）](https://michael.blog.csdn.net/article/details/109435849) |                                                              |
| [LeetCode 1642. 可以到达的最远建筑（二分查找 / 优先队列贪心）](https://michael.blog.csdn.net/article/details/109439718) |                                                              |
| [LeetCode 1644. 二叉树的最近公共祖先 II](https://michael.blog.csdn.net/article/details/119707604) |                                                              |
| [LeetCode 1646. 获取生成数组中的最大值](https://michael.blog.csdn.net/article/details/109560410) |                                                              |
| [LeetCode 1647. 字符频次唯一的最小删除次数（贪心）](https://michael.blog.csdn.net/article/details/109561232) |                                                              |
| [LeetCode 1650. 二叉树的最近公共祖先 III（哈希）](https://michael.blog.csdn.net/article/details/119707750) |                                                              |
| [LeetCode 1652. 拆炸弹（前缀和）](https://michael.blog.csdn.net/article/details/109700038) |                                                              |
| [LeetCode 1653. 使字符串平衡的最少删除次数（DP）](https://michael.blog.csdn.net/article/details/109700345) |                                                              |
| [LeetCode 1654. 到家的最少跳跃次数（BFS）](https://michael.blog.csdn.net/article/details/109702158) |                                                              |
| [LeetCode 1655. 分配重复整数（回溯）](https://michael.blog.csdn.net/article/details/109703438) |                                                              |
| [LeetCode 1656. 设计有序流（数组）](https://michael.blog.csdn.net/article/details/109703784) |                                                              |
| [LeetCode 1657. 确定两个字符串是否接近](https://michael.blog.csdn.net/article/details/109704021) |                                                              |
| [LeetCode 1658. 将 x 减到 0 的最小操作数（哈希）](https://michael.blog.csdn.net/article/details/109713477) |                                                              |
| [LeetCode 1660. 纠正二叉树（BFS）](https://michael.blog.csdn.net/article/details/119710581) |                                                              |
| [LeetCode 1662. 检查两个字符串数组是否相等](https://michael.blog.csdn.net/article/details/109943501) |                                                              |
| [LeetCode 1663. 具有给定数值的最小字符串（贪心）](https://michael.blog.csdn.net/article/details/109945744) |                                                              |
| [LeetCode 1664. 生成平衡数组的方案数（前缀和+后缀和）](https://michael.blog.csdn.net/article/details/109947860) |                                                              |
| [LeetCode 1665. 完成所有任务的最少初始能量（贪心）](https://michael.blog.csdn.net/article/details/109951983) |                                                              |
| [LeetCode 1668. 最大重复子字符串](https://michael.blog.csdn.net/article/details/110312850) |                                                              |
| [LeetCode 1669. 合并两个链表](https://michael.blog.csdn.net/article/details/110313087) |                                                              |
| [LeetCode 1670. 设计前中后队列（deque）](https://michael.blog.csdn.net/article/details/110313377) |                                                              |
| [LeetCode 1671. 得到山形数组的最少删除次数（最长上升子序DP nlogn）](https://michael.blog.csdn.net/article/details/110322462) |                                                              |
| [LeetCode 1672. 最富有客户的资产总量](https://michael.blog.csdn.net/article/details/110342814) |                                                              |
| [LeetCode 1673. 找出最具竞争力的子序列（单调栈）](https://michael.blog.csdn.net/article/details/110346793) |                                                              |
| [LeetCode 1674. 使数组互补的最少操作次数（差分思想）](https://michael.blog.csdn.net/article/details/110963941) |                                                              |
| [LeetCode 1676. 二叉树的最近公共祖先 IV](https://michael.blog.csdn.net/article/details/119708076) |                                                              |
| [LeetCode 1678. 设计 Goal 解析器](http://michael.blog.csdn.net/article/details/110733358) |                                                              |
| [LeetCode 1679. K 和数对的最大数目（哈希）](http://michael.blog.csdn.net/article/details/110733875) |                                                              |
| [LeetCode 1680. 连接连续二进制数字（位运算）](http://michael.blog.csdn.net/article/details/110734186) |                                                              |
| [LeetCode 1681. 最小不兼容性（回溯+剪枝）](http://michael.blog.csdn.net/article/details/110739766) |                                                              |
| [LeetCode 1684. 统计一致字符串的数目（哈希）](https://michael.blog.csdn.net/article/details/111087320) |                                                              |
| [LeetCode 1685. 有序数组中差绝对值之和（前缀和）](https://michael.blog.csdn.net/article/details/111087367) |                                                              |
| [LeetCode 1686. 石子游戏 VI（贪心）](https://michael.blog.csdn.net/article/details/111087463) |                                                              |
| [LeetCode 1688. 比赛中的配对次数（模拟）](https://michael.blog.csdn.net/article/details/111099423) |                                                              |
| [LeetCode 1689. 十-二进制数的最少数目（脑筋急转弯）](https://michael.blog.csdn.net/article/details/111105268) |                                                              |
| [LeetCode 1690. 石子游戏 VII（博弈DP）](https://michael.blog.csdn.net/article/details/111106376) |                                                              |
| [LeetCode 1691. 堆叠长方体的最大高度（排序+最大上升子序DP）](https://michael.blog.csdn.net/article/details/111139125) |                                                              |
| [LeetCode 1694. 重新格式化电话号码（模拟）](https://michael.blog.csdn.net/article/details/111415649) |                                                              |
| [LeetCode 1695. 删除子数组的最大得分（前缀和+哈希+双指针）](https://michael.blog.csdn.net/article/details/111415907) |                                                              |
| [LeetCode 1696. 跳跃游戏 VI（优先队列 / 单调队列）](https://michael.blog.csdn.net/article/details/111424091) |                                                              |
| [LeetCode 1697. 检查边长度限制的路径是否存在（排序+并查集）](https://michael.blog.csdn.net/article/details/111462665) |                                                              |
| [LeetCode 1700. 无法吃午餐的学生数量（队列模拟 / 不模拟）](https://michael.blog.csdn.net/article/details/111772815) |                                                              |
| [LeetCode 1701. 平均等待时间（模拟）](https://michael.blog.csdn.net/article/details/111773003) |                                                              |
| [LeetCode 1702. 修改后的最大二进制字符串（贪心）](https://michael.blog.csdn.net/article/details/111773088) |                                                              |
| [LeetCode 1704. 判断字符串的两半是否相似](https://michael.blog.csdn.net/article/details/111824889) |                                                              |
| [LeetCode 1705. 吃苹果的最大数目（优先队列）](https://michael.blog.csdn.net/article/details/111826767) |                                                              |
| [LeetCode 1706. 球会落何处（模拟）](https://michael.blog.csdn.net/article/details/111824942) |                                                              |
| [LeetCode 1707. 与数组中元素的最大异或值（Trie树）](https://michael.blog.csdn.net/article/details/117202202) |                                                              |
| [LeetCode 1708. 长度为 K 的最大子数组](https://michael.blog.csdn.net/article/details/119702510) |                                                              |
| [LeetCode 1710. 卡车上的最大单元数（排序，模拟）](https://michael.blog.csdn.net/article/details/112133070) |                                                              |
| [LeetCode 1711. 大餐计数（map计数 + 二分查找）](https://michael.blog.csdn.net/article/details/112133089) |                                                              |
| [LeetCode 1712. 将数组分成三个子数组的方案数（前缀和 + 二分查找）](https://michael.blog.csdn.net/article/details/112133125) |                                                              |
| [LeetCode 1713. 得到子序列的最少操作次数（最长上升子序DP nlogn）](https://michael.blog.csdn.net/article/details/112135082) |                                                              |
| [LeetCode 1716. 计算力扣银行的钱（等差数列）](https://michael.blog.csdn.net/article/details/112417389) |                                                              |
| [LeetCode 1717. 删除子字符串的最大得分](https://michael.blog.csdn.net/article/details/112417953) |                                                              |
| [LeetCode 1718. 构建字典序最大的可行序列（贪心+回溯）](https://michael.blog.csdn.net/article/details/115799828) |                                                              |
| [LeetCode 1720. 解码异或后的数组（位运算）](https://michael.blog.csdn.net/article/details/112426120) |                                                              |
| [LeetCode 1721. 交换链表中的节点（快慢指针）](https://michael.blog.csdn.net/article/details/112426182) |                                                              |
| [LeetCode 1722. 执行交换操作后的最小汉明距离（并查集）](https://michael.blog.csdn.net/article/details/112426211) |                                                              |
| [LeetCode 1723. 完成所有工作的最短时间（DFS+剪枝 / 状态压缩DP）](https://michael.blog.csdn.net/article/details/112426296) |                                                              |
| [LeetCode 1725. 可以形成最大正方形的矩形数目](https://michael.blog.csdn.net/article/details/112737339) |                                                              |
| [LeetCode 1726. 同积元组（排列组合）](https://michael.blog.csdn.net/article/details/112738288) |                                                              |
| [LeetCode 1727. 重新排列后的最大子矩阵（前缀和+排序）](https://michael.blog.csdn.net/article/details/112753593) |                                                              |
| [LeetCode 1730. 获取食物的最短路径（BFS）](https://michael.blog.csdn.net/article/details/119711223) |                                                              |
| [LeetCode 1732. 找到最高海拔](https://michael.blog.csdn.net/article/details/113068007) |                                                              |
| [LeetCode 1733. 需要教语言的最少人数（哈希+枚举）](https://michael.blog.csdn.net/article/details/113071632) |                                                              |
| [LeetCode 1734. 解码异或后的排列（位运算）](https://michael.blog.csdn.net/article/details/113068427) |                                                              |
| [LeetCode 1736. 替换隐藏数字得到的最晚时间](https://michael.blog.csdn.net/article/details/113082734) |                                                              |
| [LeetCode 1737. 满足三条件之一需改变的最少字符数（计数）](https://michael.blog.csdn.net/article/details/113083679) |                                                              |
| [LeetCode 1738. 找出第 K 大的异或坐标值（DP）](https://michael.blog.csdn.net/article/details/113086195) |                                                              |
| [LeetCode 1739. 放置盒子（数学）](https://michael.blog.csdn.net/article/details/121310831) |                                                              |
| [LeetCode 1742. 盒子中小球的最大数量](https://michael.blog.csdn.net/article/details/113465352) |                                                              |
| [LeetCode 1743. 从相邻元素对还原数组（拓扑排序）](https://michael.blog.csdn.net/article/details/113465643) |                                                              |
| [LeetCode 1744. 你能在你最喜欢的那天吃到你最喜欢的糖果吗？（前缀和）](https://michael.blog.csdn.net/article/details/113466143) |                                                              |
| [LeetCode 1745. 回文串分割 IV（区间DP）](https://michael.blog.csdn.net/article/details/113468128) |                                                              |
| [LeetCode 1748. 唯一元素的和](https://michael.blog.csdn.net/article/details/113732986) |                                                              |
| [LeetCode 1749. 任意子数组和的绝对值的最大值（前缀和）](https://michael.blog.csdn.net/article/details/113733076) |                                                              |
| [LeetCode 1750. 删除字符串两端相同字符后的最短长度（双指针）](https://michael.blog.csdn.net/article/details/113733199) |                                                              |
| [LeetCode 1751. 最多可以参加的会议数目 II（DP + 二分查找）](https://michael.blog.csdn.net/article/details/113748485) |                                                              |
| [LeetCode 1752. 检查数组是否经排序和轮转得到](https://michael.blog.csdn.net/article/details/113740068) |                                                              |
| [LeetCode 1753. 移除石子的最大得分（优先队列）](https://michael.blog.csdn.net/article/details/113741201) |                                                              |
| [LeetCode 1754. 构造字典序最大的合并字符串](https://michael.blog.csdn.net/article/details/113746916) |                                                              |
| [LeetCode 1755. 最接近目标值的子序列和（状态枚举 + 双指针）](https://michael.blog.csdn.net/article/details/113774587) |                                                              |
| [LeetCode 1758. 生成交替二进制字符串的最少操作数（DP）](https://blog.csdn.net/qq_21201267/article/details/113814567) |                                                              |
| [LeetCode 1759. 统计同构子字符串的数目](https://blog.csdn.net/qq_21201267/article/details/113814628) |                                                              |
| [LeetCode 1760. 袋子里最少数目的球（二分查找）](https://blog.csdn.net/qq_21201267/article/details/113814817) |                                                              |
| [LeetCode 1763. 最长的美好子字符串](https://blog.csdn.net/qq_21201267/article/details/113917388) |                                                              |
| [LeetCode 1764. 通过连接另一个数组的子数组得到一个数组](https://blog.csdn.net/qq_21201267/article/details/113919507) |                                                              |
| [LeetCode 1765. 地图中的最高点（BFS）](https://blog.csdn.net/qq_21201267/article/details/113919848) |                                                              |
| [LeetCode 1768. 交替合并字符串](https://blog.csdn.net/qq_21201267/article/details/113921203) |                                                              |
| [LeetCode 1769. 移动所有球到每个盒子所需的最小操作数（前缀和）](https://blog.csdn.net/qq_21201267/article/details/113922455) |                                                              |
| [LeetCode 1770. 执行乘法运算的最大分数（DP）](https://blog.csdn.net/qq_21201267/article/details/113923552) |                                                              |
| [LeetCode 1771. 由子序列构造的最长回文串的长度（最长回文子序）](https://michael.blog.csdn.net/article/details/113925129) |                                                              |
| [LeetCode 1773. 统计匹配检索规则的物品数量](https://michael.blog.csdn.net/article/details/114227831) |                                                              |
| [LeetCode 1774. 最接近目标价格的甜点成本（DFS / 01背包）](https://michael.blog.csdn.net/article/details/114227995) |                                                              |
| [LeetCode 1775. 通过最少操作次数使数组的和相等（贪心+双指针）](https://michael.blog.csdn.net/article/details/114228384) |                                                              |
| [LeetCode 1776. 车队 II（单调栈）](https://michael.blog.csdn.net/article/details/114228647) |                                                              |
| [LeetCode 1779. 找到最近的有相同 X 或 Y 坐标的点](https://michael.blog.csdn.net/article/details/114478215) |                                                              |
| [LeetCode 1780. 判断一个数字是否可以表示成三的幂的和（位运算）](https://michael.blog.csdn.net/article/details/114478416) |                                                              |
| [LeetCode 1781. 所有子字符串美丽值之和](https://michael.blog.csdn.net/article/details/114478772) |                                                              |
| [LeetCode 1784. 检查二进制字符串字段](https://michael.blog.csdn.net/article/details/114481711) |                                                              |
| [LeetCode 1785. 构成特定和需要添加的最少元素（贪心）](https://michael.blog.csdn.net/article/details/114481755) |                                                              |
| [LeetCode 1786. 从第一个节点出发到最后一个节点的受限路径数（迪杰斯特拉 + 拓扑排序）](https://michael.blog.csdn.net/article/details/114481911) |                                                              |
| [LeetCode 1790. 仅执行一次字符串交换能否使两个字符串相等](https://michael.blog.csdn.net/article/details/114807929) |                                                              |
| [LeetCode 1791. 找出星型图的中心节点（图出入度）](https://michael.blog.csdn.net/article/details/114808435) |                                                              |
| [LeetCode 1792. 最大平均通过率（优先队列）](https://michael.blog.csdn.net/article/details/114810133) |                                                              |
| [LeetCode 1793. 好子数组的最大分数（单调栈）](https://michael.blog.csdn.net/article/details/114810826) |                                                              |
| [LeetCode 1796. 字符串中第二大的数字](https://michael.blog.csdn.net/article/details/115037618) |                                                              |
| [LeetCode 1797. 设计一个验证系统（map）](https://michael.blog.csdn.net/article/details/115037663) |                                                              |
| [LeetCode 1798. 你能构造出连续值的最大数目](https://michael.blog.csdn.net/article/details/115037838) |                                                              |
| [LeetCode 1799. N 次操作后的最大分数和（回溯 / 状态压缩DP）](https://michael.blog.csdn.net/article/details/115038679) |                                                              |
| [LeetCode 1800. 最大升序子数组和](https://michael.blog.csdn.net/article/details/115047160) |                                                              |
| [LeetCode 1801. 积压订单中的订单总数（map）](https://michael.blog.csdn.net/article/details/115047195) |                                                              |
| [LeetCode 1802. 有界数组中指定下标处的最大值（思维题）](https://michael.blog.csdn.net/article/details/115055483) |                                                              |
| [LeetCode 1805. 字符串中不同整数的数目（哈希set）](https://michael.blog.csdn.net/article/details/115279427) |                                                              |
| [LeetCode 1806. 还原排列的最少操作步数（模拟）](https://michael.blog.csdn.net/article/details/115280157) |                                                              |
| [LeetCode 1807. 替换字符串中的括号内容（哈希map）](https://michael.blog.csdn.net/article/details/115280558) |                                                              |
| [LeetCode 1808. 好因子的最大数目（整数拆分，乘积最大）](https://michael.blog.csdn.net/article/details/115283145) |                                                              |
| [LeetCode 1812. 判断国际象棋棋盘中一个格子的颜色](https://michael.blog.csdn.net/article/details/115423192) |                                                              |
| [LeetCode 1813. 句子相似性 III](https://michael.blog.csdn.net/article/details/115423380) |                                                              |
| [LeetCode 1814. 统计一个数组中好对子的数目（哈希）](https://michael.blog.csdn.net/article/details/115423517) |                                                              |
| [LeetCode 1816. 截断句子](https://michael.blog.csdn.net/article/details/115426933) |                                                              |
| [LeetCode 1817. 查找用户活跃分钟数（哈希）](https://michael.blog.csdn.net/article/details/115426967) |                                                              |
| [LeetCode 1818. 绝对差值和（二分查找）](https://michael.blog.csdn.net/article/details/115427000) |                                                              |
| [LeetCode 1819. 序列中不同最大公约数的数目](https://michael.blog.csdn.net/article/details/115428785) |                                                              |
| [LeetCode 1822. 数组元素积的符号](https://michael.blog.csdn.net/article/details/115598847) |                                                              |
| [LeetCode 1824. 最少侧跳次数（DP）](https://michael.blog.csdn.net/article/details/115599996) |                                                              |
| [LeetCode 1825. 求出 MK 平均值（set + queue）](https://michael.blog.csdn.net/article/details/115603169) |                                                              |
| [LeetCode 1826. 有缺陷的传感器（枚举）](https://michael.blog.csdn.net/article/details/119702272) |                                                              |
| [LeetCode 1827. 最少操作使数组递增](https://michael.blog.csdn.net/article/details/115804095) |                                                              |
| [LeetCode 1828. 统计一个圆中点的数目](https://michael.blog.csdn.net/article/details/115804135) |                                                              |
| [LeetCode 1829. 每个查询的最大异或值（前缀异或 + 位运算）](https://michael.blog.csdn.net/article/details/115804172) |                                                              |
| [LeetCode 1832. 判断句子是否为全字母句](https://michael.blog.csdn.net/article/details/115823557) |                                                              |
| [LeetCode 1833. 雪糕的最大数量（贪心）](https://michael.blog.csdn.net/article/details/115823614) |                                                              |
| [LeetCode 1834. 单线程 CPU（排序 + 优先队列）](https://michael.blog.csdn.net/article/details/115823770) |                                                              |
| [LeetCode 1835. 所有数对按位与结果的异或和（位运算 (a&b)^(a&c) = a&(b^c) ）](https://michael.blog.csdn.net/article/details/115831551) |                                                              |
| [LeetCode 1837. K 进制表示下的各位数字总和](https://michael.blog.csdn.net/article/details/116122961) |                                                              |
| [LeetCode 1838. 最高频元素的频数（二分查找）](https://michael.blog.csdn.net/article/details/116130754) |                                                              |
| [LeetCode 1839. 所有元音按顺序排布的最长子字符串（滑动窗口）](https://michael.blog.csdn.net/article/details/116132461) |                                                              |
| [LeetCode 1844. 将所有数字用字符替换](https://michael.blog.csdn.net/article/details/116355919) |                                                              |
| [LeetCode 1845. 座位预约管理系统（set）](https://michael.blog.csdn.net/article/details/116357409) |                                                              |
| [LeetCode 1846. 减小和重新排列数组后的最大元素](https://michael.blog.csdn.net/article/details/116396336) |                                                              |
| [LeetCode 1847. 最近的房间（排序离线计算 + 二分查找）](https://michael.blog.csdn.net/article/details/116398943) |                                                              |
| [LeetCode 1848. 到目标元素的最小距离](https://michael.blog.csdn.net/article/details/116357592) |                                                              |
| [LeetCode 1849. 将字符串拆分为递减的连续值（回溯）](https://michael.blog.csdn.net/article/details/116403000) |                                                              |
| [LeetCode 1851. 包含每个查询的最小区间（排序 + 离线查询 + 优先队列）](https://michael.blog.csdn.net/article/details/116405318) |                                                              |
| [LeetCode 1852. 每个子数组的数字种类数（滑窗）](https://michael.blog.csdn.net/article/details/119708196) |                                                              |
| [LeetCode 1854. 人口最多的年份（差分）](https://michael.blog.csdn.net/article/details/116810082) |                                                              |
| [LeetCode 1855. 下标对中的最大距离（双指针）](https://michael.blog.csdn.net/article/details/116859334) |                                                              |
| [LeetCode 1856. 子数组最小乘积的最大值（前缀和 + 单调栈）](https://michael.blog.csdn.net/article/details/116862645) |                                                              |
| [LeetCode 1859. 将句子排序](https://michael.blog.csdn.net/article/details/116885278) |                                                              |
| [LeetCode 1860. 增长的内存泄露（等差数列）](https://michael.blog.csdn.net/article/details/116886633) |                                                              |
| [LeetCode 1861. 旋转盒子（前缀和）](https://michael.blog.csdn.net/article/details/116888406) |                                                              |
| [LeetCode 1863. 找出所有子集的异或总和再求和（DFS）](https://michael.blog.csdn.net/article/details/116905069) |                                                              |
| [LeetCode 1864. 构成交替字符串需要的最小交换次数](https://michael.blog.csdn.net/article/details/117391716) |                                                              |
| [LeetCode 1865. 找出和为指定值的下标对（哈希）](https://michael.blog.csdn.net/article/details/117392116) |                                                              |
| [LeetCode 1868. 两个行程编码数组的积（双指针）](https://michael.blog.csdn.net/article/details/119858130) |                                                              |
| [LeetCode 1869. 哪种连续子字符串更长](https://michael.blog.csdn.net/article/details/117196756) |                                                              |
| [LeetCode 1870. 准时到达的列车最小时速（二分查找）](https://michael.blog.csdn.net/article/details/117197407) |                                                              |
| [LeetCode 1871. 跳跃游戏 VII（贪心）](https://michael.blog.csdn.net/article/details/117198626) |                                                              |
| [LeetCode 1874. 两个数组的最小乘积和](https://michael.blog.csdn.net/article/details/119712494) |                                                              |
| [LeetCode 1876. 长度为三且各字符不同的子字符串](https://michael.blog.csdn.net/article/details/117393042) |                                                              |
| [LeetCode 1877. 数组中最大数对和的最小值（贪心）](https://michael.blog.csdn.net/article/details/117393058) |                                                              |
| [LeetCode 1878. 矩阵中最大的三个菱形和（模拟）](https://michael.blog.csdn.net/article/details/117393155) |                                                              |
| [LeetCode 1879. 两个数组最小的异或值之和（状态压缩DP）](https://michael.blog.csdn.net/article/details/117393227) |                                                              |
| [LeetCode 1880. 检查某单词是否等于两单词之和](https://michael.blog.csdn.net/article/details/117400792) |                                                              |
| [LeetCode 1885. Count Pairs in Two Arrays（二分查找）](https://michael.blog.csdn.net/article/details/119857452) |                                                              |
| [LeetCode 1886. 判断矩阵经轮转后是否一致](https://michael.blog.csdn.net/article/details/117636386) |                                                              |
| [LeetCode 1887. 使数组元素相等的减少操作次数（map）](https://michael.blog.csdn.net/article/details/117827834) |                                                              |
| [LeetCode 1891. 割绳子（二分查找）](https://michael.blog.csdn.net/article/details/119708324) |                                                              |
| [LeetCode 1893. 检查是否区域内所有整数都被覆盖（差分）](https://michael.blog.csdn.net/article/details/117884374) |                                                              |
| [LeetCode 1894. 找到需要补充粉笔的学生编号](https://michael.blog.csdn.net/article/details/117886348) |                                                              |
| [LeetCode 1897. 重新分配字符使所有字符串都相等](https://michael.blog.csdn.net/article/details/117886470) |                                                              |
| [LeetCode 1899. 合并若干三元组以形成目标三元组](https://michael.blog.csdn.net/article/details/117886808) |                                                              |
| [LeetCode 1901. 找出顶峰元素 II（二分查找）](https://michael.blog.csdn.net/article/details/121459061) |                                                              |
| [LeetCode 1903. 字符串中的最大奇数](https://michael.blog.csdn.net/article/details/118068540) |                                                              |
| [LeetCode 1904. 你完成的完整对局数](https://michael.blog.csdn.net/article/details/118068750) |                                                              |
| [LeetCode 1905. 统计子岛屿（BFS）](https://michael.blog.csdn.net/article/details/118069372) |                                                              |
| [LeetCode 1909. 删除一个元素使数组严格递增](https://michael.blog.csdn.net/article/details/120885034) |                                                              |
| [LeetCode 1910. 删除一个字符串中所有出现的给定子字符串](https://michael.blog.csdn.net/article/details/118273714) |                                                              |
| [LeetCode 1911. 最大子序列交替和（动态规划）](https://michael.blog.csdn.net/article/details/118274111) |                                                              |
| [LeetCode 1912. 设计电影租借系统（map+set）](https://michael.blog.csdn.net/article/details/118281962) |                                                              |
| [LeetCode 1913. 两个数对之间的最大乘积差](https://michael.blog.csdn.net/article/details/118627688) |                                                              |
| [LeetCode 1920. 基于排列构建数组](https://michael.blog.csdn.net/article/details/118627914) |                                                              |
| [LeetCode 1921. 消灭怪物的最大数量（排序）](https://michael.blog.csdn.net/article/details/118629696) |                                                              |
| [LeetCode 1922. 统计好数字的数目（快速幂）](https://michael.blog.csdn.net/article/details/118628416) |                                                              |
| [LeetCode 1925. 统计平方和三元组的数目](https://michael.blog.csdn.net/article/details/118652812) |                                                              |
| [LeetCode 1926. 迷宫中离入口最近的出口（BFS）](https://michael.blog.csdn.net/article/details/118652950) |                                                              |
| [LeetCode 1930. 长度为 3 的不同回文子序列（计数）](https://michael.blog.csdn.net/article/details/118771767) |                                                              |
| [LeetCode 1933. 判断字符串是否可分解为值均等的子串](https://michael.blog.csdn.net/article/details/118629253) |                                                              |
| [LeetCode 1935. 可以输入的最大单词数](https://michael.blog.csdn.net/article/details/118879051) |                                                              |
| [LeetCode 1936. 新增的最少台阶数](https://michael.blog.csdn.net/article/details/118880382) |                                                              |
| [LeetCode 1937. 扣分后的最大得分（动态规划）](https://michael.blog.csdn.net/article/details/118882023) |                                                              |
| [LeetCode 1940. 排序数组之间的最长公共子序列（二分查找）](https://michael.blog.csdn.net/article/details/119712692) |                                                              |
| [LeetCode 1941. 检查是否所有字符出现次数相同](https://michael.blog.csdn.net/article/details/119086471) |                                                              |
| [LeetCode 1942. 最小未被占据椅子的编号（set）](https://michael.blog.csdn.net/article/details/119087079) |                                                              |
| [LeetCode 1943. 描述绘画结果（差分思想）](https://michael.blog.csdn.net/article/details/119087554) |                                                              |
| [LeetCode 1944. 队列中可以看到的人数（单调栈）](https://michael.blog.csdn.net/article/details/119088210) |                                                              |
| [LeetCode 1945. 字符串转化后的各位数字之和](https://michael.blog.csdn.net/article/details/119099700) |                                                              |
| [LeetCode 1947. 最大兼容性评分和（状态枚举DP）](https://michael.blog.csdn.net/article/details/126071744) |                                                              |
| [LeetCode 1952. 三除数](https://michael.blog.csdn.net/article/details/119302708) |                                                              |
| [LeetCode 1953. 你可以工作的最大周数](https://michael.blog.csdn.net/article/details/119303507) |                                                              |
| [LeetCode 1954. 收集足够苹果的最小花园周长（数学）](https://michael.blog.csdn.net/article/details/119303971) |                                                              |
| [LeetCode 1955. 统计特殊子序列的数目](https://michael.blog.csdn.net/article/details/119305188) |                                                              |
| [LeetCode 1957. 删除字符使字符串变好](https://michael.blog.csdn.net/article/details/119512703) |                                                              |
| [LeetCode 1958. 检查操作是否合法（模拟）](https://michael.blog.csdn.net/article/details/119513540) |                                                              |
| [LeetCode 1961. 检查字符串是否为数组前缀](https://michael.blog.csdn.net/article/details/119532748) |                                                              |
| [LeetCode 1962. 移除石子使总数最小（优先队列）](https://michael.blog.csdn.net/article/details/119533053) |                                                              |
| [LeetCode 1966. Binary Searchable Numbers in an Unsorted Array](https://michael.blog.csdn.net/article/details/119845600) |                                                              |
| [LeetCode 1967. 作为子字符串出现在单词中的字符串数目](https://michael.blog.csdn.net/article/details/119719041) |                                                              |
| [LeetCode 1968. 构造元素不等于两相邻元素平均值的数组](https://michael.blog.csdn.net/article/details/119719376) |                                                              |
| [LeetCode 1971. Find if Path Exists in Graph（图的遍历）](https://michael.blog.csdn.net/article/details/119881694) |                                                              |
| [LeetCode 1973. Count Nodes Equal to Sum of Descendants（DFS）](https://michael.blog.csdn.net/article/details/119845296) |                                                              |
| [LeetCode 1974. 使用特殊打字机键入单词的最少时间](https://michael.blog.csdn.net/article/details/119881731) |                                                              |
| [LeetCode 1976. 到达目的地的方案数（迪杰斯特拉 Python 优先队列）](https://michael.blog.csdn.net/article/details/119921743) |                                                              |
| [LeetCode 1979. 找出数组的最大公约数](https://michael.blog.csdn.net/article/details/119881745) |                                                              |
| [LeetCode 1980. 找出不同的二进制字符串](https://michael.blog.csdn.net/article/details/119902679) |                                                              |
| [LeetCode 1981. 最小化目标值与所选元素的差（DP）](https://michael.blog.csdn.net/article/details/119902747) |                                                              |
| [LeetCode 1984. 学生分数的最小差值](https://michael.blog.csdn.net/article/details/119978992) |                                                              |
| [LeetCode 1985. 找出数组中的第 K 大整数（排序）](https://michael.blog.csdn.net/article/details/119979083) |                                                              |
| [LeetCode 1991. 找到数组的中间位置（前缀和）](https://michael.blog.csdn.net/article/details/120113495) |                                                              |
| [LeetCode 1992. 找到所有的农场组（BFS）](https://michael.blog.csdn.net/article/details/120113636) |                                                              |
| [LeetCode 2000. 反转单词前缀](https://michael.blog.csdn.net/article/details/120250026) |                                                              |
| [LeetCode 2001. 可互换矩形的组数](https://michael.blog.csdn.net/article/details/120250152) |                                                              |
| [LeetCode 2002. 两个回文子序列长度的最大乘积（状态压缩+枚举状态子集+预处理）](https://michael.blog.csdn.net/article/details/120251282) |                                                              |
| [LeetCode 2007. 从双倍数组中还原原数组（map）](https://michael.blog.csdn.net/article/details/120378599) |                                                              |
| [LeetCode 2008. 出租车的最大盈利（DP）](https://michael.blog.csdn.net/article/details/120380729) |                                                              |
| [LeetCode 2011. 执行操作后的变量值](https://michael.blog.csdn.net/article/details/120394205) |                                                              |
| [LeetCode 2012. 数组美丽值求和](https://michael.blog.csdn.net/article/details/120394393) |                                                              |
| [LeetCode 2013. 检测正方形（字典）](https://michael.blog.csdn.net/article/details/120394720) |                                                              |
| [LeetCode 2016. 增量元素之间的最大差值](https://michael.blog.csdn.net/article/details/120618669) |                                                              |
| [LeetCode 2017. 网格游戏（前缀和）](https://michael.blog.csdn.net/article/details/120619456) |                                                              |
| [LeetCode 2018. 判断单词是否能放入填字游戏内（模拟）](https://michael.blog.csdn.net/article/details/120642356) |                                                              |
| [LeetCode 2022. 将一维数组转变成二维数组](https://michael.blog.csdn.net/article/details/120642711) |                                                              |
| [LeetCode 2023. 连接后等于目标字符串的字符串对](https://michael.blog.csdn.net/article/details/120642823) |                                                              |
| [LeetCode 2027. 转换字符串的最少操作次数](https://michael.blog.csdn.net/article/details/120650036) |                                                              |
| [LeetCode 2028. 找出缺失的观测数据](https://michael.blog.csdn.net/article/details/120650485) |                                                              |
| [LeetCode 2032. 至少在两个数组中出现的值（哈希/位运算）](https://michael.blog.csdn.net/article/details/120686430) |                                                              |
| [LeetCode 2033. 获取单值网格的最小操作数（贪心）](https://michael.blog.csdn.net/article/details/120686846) |                                                              |
| [LeetCode 2034. 股票价格波动（set + map）](https://michael.blog.csdn.net/article/details/120687673) |                                                              |
| [LeetCode 2035. 将数组分成两个数组并最小化数组和的差（状态压缩DP）](https://michael.blog.csdn.net/article/details/120690250) |                                                              |
| [LeetCode 2037. 使每位学生都有座位的最少移动次数](https://michael.blog.csdn.net/article/details/120807101) |                                                              |
| [LeetCode 2038. 如果相邻两个颜色均相同则删除当前颜色](https://michael.blog.csdn.net/article/details/120807581) |                                                              |
| [LeetCode 2039. 网络空闲的时刻（BFS）](https://michael.blog.csdn.net/article/details/120808236) |                                                              |
| [LeetCode 2040. 两个有序数组的第 K 小乘积（嵌套二分查找）](https://michael.blog.csdn.net/article/details/120813594) |                                                              |
| [LeetCode 2042. 检查句子中的数字是否递增](https://michael.blog.csdn.net/article/details/120819583) |                                                              |
| [LeetCode 2043. 简易银行系统](https://michael.blog.csdn.net/article/details/120824805) |                                                              |
| [LeetCode 2044. 统计按位或能得到最大值的子集数目（状态压缩DP）](https://michael.blog.csdn.net/article/details/120831782) |                                                              |
| [LeetCode 2047. 句子中的有效单词数](https://michael.blog.csdn.net/article/details/120932086) |                                                              |
| [LeetCode 2048. 下一个更大的数值平衡数（枚举）](https://michael.blog.csdn.net/article/details/120940024) |                                                              |
| [LeetCode 2049. 统计最高分的节点数目（DFS）](https://michael.blog.csdn.net/article/details/120941597) |                                                              |
| [LeetCode 2050. 并行课程 III（拓扑排序）](https://michael.blog.csdn.net/article/details/121047501) |                                                              |
| [LeetCode 2053. 数组中第 K 个独一无二的字符串（哈希）](https://michael.blog.csdn.net/article/details/121060942) |                                                              |
| [LeetCode 2055. 蜡烛之间的盘子（前缀和）](https://michael.blog.csdn.net/article/details/121175410) |                                                              |
| [LeetCode 2057. 值相等的最小索引](https://michael.blog.csdn.net/article/details/121189298) |                                                              |
| [LeetCode 2058. 找出临界点之间的最小和最大距离（链表）](https://michael.blog.csdn.net/article/details/121189597) |                                                              |
| [LeetCode 2059. 转化数字的最小运算数（BFS）](https://michael.blog.csdn.net/article/details/121190700) |                                                              |
| [LeetCode 2062. 统计字符串中的元音子字符串](https://michael.blog.csdn.net/article/details/121191511) |                                                              |
| [LeetCode 2063. 所有子字符串中的元音（数学）](https://michael.blog.csdn.net/article/details/121191739) |                                                              |
| [LeetCode 2064. 分配给商店的最多商品的最小值（二分查找）](https://michael.blog.csdn.net/article/details/121195388) |                                                              |
| [LeetCode 2065. 最大化一张图中的路径价值（DFS）](https://michael.blog.csdn.net/article/details/121195948) |                                                              |
| [LeetCode 2068. 检查两个字符串是否几乎相等](https://michael.blog.csdn.net/article/details/121315678) |                                                              |
| [LeetCode 2069. 模拟行走机器人 II（模拟）](https://michael.blog.csdn.net/article/details/121317313) |                                                              |
| [LeetCode 2070. 每一个查询的最大美丽值（离线查询+排序+优先队列）](https://michael.blog.csdn.net/article/details/121318384) |                                                              |
| [LeetCode 2071. 你可以安排的最多任务数目（二分查找）](https://michael.blog.csdn.net/article/details/121321694) |                                                              |
| [LeetCode 2073. 买票需要的时间](https://michael.blog.csdn.net/article/details/121323245) |                                                              |
| [LeetCode 2074. 反转偶数长度组的节点（链表）](https://michael.blog.csdn.net/article/details/121324834) |                                                              |
| [LeetCode 2075. 解码斜向换位密码（模拟）](https://michael.blog.csdn.net/article/details/121325243) |                                                              |
| [LeetCode 2076. 处理含限制条件的好友请求（并查集）](https://michael.blog.csdn.net/article/details/121350640) |                                                              |
| [LeetCode 2078. 两栋颜色不同且距离最远的房子](https://michael.blog.csdn.net/article/details/121452542) |                                                              |
| [LeetCode 2079. 给植物浇水（前缀和）](https://michael.blog.csdn.net/article/details/121452891) |                                                              |
| [LeetCode 2080. 区间内查询数字的频率（哈希+二分查找）](https://michael.blog.csdn.net/article/details/121453903) |                                                              |
| [LeetCode 2085. 统计出现过一次的公共字符串（哈希）](https://michael.blog.csdn.net/article/details/121587963) |                                                              |
| [LeetCode 2086. 从房屋收集雨水需要的最少水桶数（贪心）](https://michael.blog.csdn.net/article/details/121592327) |                                                              |
| [LeetCode 2087. 网格图中机器人回家的最小代价（脑筋急转弯）](https://michael.blog.csdn.net/article/details/121593262) |                                                              |
| [LeetCode 2089. 找出数组排序后的目标下标](https://michael.blog.csdn.net/article/details/121593708) |                                                              |
| [LeetCode 2090. 半径为 k 的子数组平均值（滑窗）](https://michael.blog.csdn.net/article/details/121594157) |                                                              |
| [LeetCode 2091. 从数组中移除最大值和最小值（一次遍历）](https://michael.blog.csdn.net/article/details/121594444) |                                                              |
| [LeetCode 2092. 找出知晓秘密的所有专家（并查集）](https://michael.blog.csdn.net/article/details/121596465) |                                                              |
| [LeetCode 2094. 找出 3 位偶数](https://michael.blog.csdn.net/article/details/121728020) |                                                              |
| [LeetCode 2095. 删除链表的中间节点（快慢指针）](https://michael.blog.csdn.net/article/details/121728462) |                                                              |
| [LeetCode 2096. 从二叉树一个节点到另一个节点每一步的方向（最小公共祖先）](https://michael.blog.csdn.net/article/details/121732114) |                                                              |
| [LeetCode 2097. 合法重新排列数对（欧拉路径）](https://michael.blog.csdn.net/article/details/121733716) |                                                              |
| [LeetCode 2099. 找到和最大的长度为 K 的子序列](https://michael.blog.csdn.net/article/details/121883369) |                                                              |
| [LeetCode 2100. 适合种地的日子（计数）](https://michael.blog.csdn.net/article/details/121884024) |                                                              |
| [LeetCode 2101. 引爆最多的炸弹（图的遍历）](https://michael.blog.csdn.net/article/details/121884665) |                                                              |
| [LeetCode 2103. 环和杆（位运算）](https://michael.blog.csdn.net/article/details/121885968) |                                                              |
| [LeetCode 2104. 子数组范围和（单调栈）](https://michael.blog.csdn.net/article/details/121894600) |                                                              |
| [LeetCode 2105. 给植物浇水 II（双指针）](https://michael.blog.csdn.net/article/details/122015184) |                                                              |
| [LeetCode 2108. 找出数组中的第一个回文字符串](https://michael.blog.csdn.net/article/details/122022315) |                                                              |
| [LeetCode 2109. 向字符串添加空格](https://michael.blog.csdn.net/article/details/122022409) |                                                              |
| [LeetCode 2110. 股票平滑下跌阶段的数目（滑动窗口）](https://michael.blog.csdn.net/article/details/122022673) |                                                              |
| [LeetCode 2114. 句子中的最多单词数](https://blog.csdn.net/qq_21201267/article/details/122263896) |                                                              |
| [LeetCode 2115. 从给定原材料中找到所有可以做出的菜（拓扑排序）](https://blog.csdn.net/qq_21201267/article/details/122267127) |                                                              |
| [LeetCode 2116. 判断一个括号字符串是否有效（栈）](https://blog.csdn.net/qq_21201267/article/details/122268276) |                                                              |
| [LeetCode 2119. 反转两次的数字](https://blog.csdn.net/qq_21201267/article/details/122268581) |                                                              |
| [LeetCode 2120. 执行所有后缀指令（模拟）](https://blog.csdn.net/qq_21201267/article/details/122269874) |                                                              |
| [LeetCode 2121. 相同元素的间隔之和（前缀和）](https://blog.csdn.net/qq_21201267/article/details/122271240) |                                                              |
| [LeetCode 2124. 检查是否所有 A 都在 B 之前](https://blog.csdn.net/qq_21201267/article/details/122279653) |                                                              |
| [LeetCode 2125. 银行中的激光束数量](https://blog.csdn.net/qq_21201267/article/details/122279860) |                                                              |
| [LeetCode 2126. 摧毁小行星（贪心）](https://blog.csdn.net/qq_21201267/article/details/122280033) |                                                              |
| [LeetCode 2129. 将标题首字母大写](https://blog.csdn.net/qq_21201267/article/details/122394761) |                                                              |
| [LeetCode 2130. 链表最大孪生和（链表快慢指针+反转链表+双指针）](https://blog.csdn.net/qq_21201267/article/details/122394983) |                                                              |
| [LeetCode 2131. 连接两字母单词得到的最长回文串](https://blog.csdn.net/qq_21201267/article/details/122395504) |                                                              |
| [LeetCode 2132. 用邮票贴满网格图（DP/二维差分）](https://blog.csdn.net/qq_21201267/article/details/122398242) |                                                              |
| [LeetCode 2133. 检查是否每一行每一列都包含全部整数](https://blog.csdn.net/qq_21201267/article/details/122398730) |                                                              |
| [LeetCode 2134. 最少交换次数来组合所有的 1 II（数组*2 + 滑动窗口）](https://blog.csdn.net/qq_21201267/article/details/122399026) |                                                              |
| [LeetCode 2135. 统计追加字母可以获得的单词数（位运算+哈希）](https://blog.csdn.net/qq_21201267/article/details/122400089) |                                                              |
| [LeetCode 2136. 全部开花的最早一天（贪心）](https://blog.csdn.net/qq_21201267/article/details/122400643) |                                                              |
| [LeetCode 2138. 将字符串拆分为若干长度为 k 的组](https://blog.csdn.net/qq_21201267/article/details/122521582) |                                                              |
| [LeetCode 2139. 得到目标值的最少行动次数（贪心）](https://blog.csdn.net/qq_21201267/article/details/122522259) |                                                              |
| [LeetCode 2140. 解决智力问题（动态规划）](https://blog.csdn.net/qq_21201267/article/details/122526427) |                                                              |
| [LeetCode 2141. 同时运行 N 台电脑的最长时间（二分查找）](https://michael.blog.csdn.net/article/details/122527701) |                                                              |
| [LeetCode 2144. 打折购买糖果的最小开销（贪心）](https://michael.blog.csdn.net/article/details/122653081) |                                                              |
| [LeetCode 2145. 统计隐藏数组数目（前缀和）](https://michael.blog.csdn.net/article/details/122653480) |                                                              |
| [LeetCode 2146. 价格范围内最高排名的 K 样物品（BFS）](https://michael.blog.csdn.net/article/details/122653939) |                                                              |
| [LeetCode 2147. 分隔长廊的方案数](https://michael.blog.csdn.net/article/details/122654981) |                                                              |
| [LeetCode 2148. 元素计数](https://michael.blog.csdn.net/article/details/122655093) |                                                              |
| [LeetCode 2149. 按符号重排数组（双指针）](https://michael.blog.csdn.net/article/details/122655254) |                                                              |
| [LeetCode 2150. 找出数组中的所有孤独数字（哈希）](https://michael.blog.csdn.net/article/details/122655347) |                                                              |
| [LeetCode 2151. 基于陈述统计最多好人数（状态压缩）](https://michael.blog.csdn.net/article/details/122693286) |                                                              |
| [LeetCode 2154. 将找到的值乘以 2](https://michael.blog.csdn.net/article/details/122752080) |                                                              |
| [LeetCode 2155. 分组得分最高的所有下标（前缀和）](https://michael.blog.csdn.net/article/details/122752142) |                                                              |
| [LeetCode 2156. 查找给定哈希值的子串（字符串哈希）](https://michael.blog.csdn.net/article/details/122752956) |                                                              |
| [LeetCode 2157. 字符串分组（状态压缩+位运算+图的遍历）](https://michael.blog.csdn.net/article/details/122754457) |                                                              |
| [LeetCode 2160. 拆分数位后四位数字的最小和](https://michael.blog.csdn.net/article/details/122801178) |                                                              |
| [LeetCode 2161. 根据给定数字划分数组](https://michael.blog.csdn.net/article/details/122801390) |                                                              |
| [LeetCode 2162. 设置时间的最少代价（枚举）](https://michael.blog.csdn.net/article/details/122802170) |                                                              |
| [LeetCode 2164. 对奇偶下标分别排序](https://michael.blog.csdn.net/article/details/122834650) |                                                              |
| [LeetCode 2165. 重排数字的最小值（计数）](https://michael.blog.csdn.net/article/details/122834677) |                                                              |
| [LeetCode 2166. 设计位集（Bitset）](https://michael.blog.csdn.net/article/details/122853231) |                                                              |
| [LeetCode 2169. 得到 0 的操作数](https://michael.blog.csdn.net/article/details/122935651) |                                                              |
| [LeetCode 2171. 拿出最少数目的魔法豆（排序）](https://michael.blog.csdn.net/article/details/122935658) |                                                              |
| [LeetCode 2176. 统计数组中相等且可以被整除的数对](https://michael.blog.csdn.net/article/details/123033678) |                                                              |
| [LeetCode 2177. 找到和为给定整数的三个连续整数](https://michael.blog.csdn.net/article/details/123033725) |                                                              |
| [LeetCode 2178. 拆分成最多数目的偶整数之和（等差数列求和）](https://michael.blog.csdn.net/article/details/123034279) |                                                              |
| [LeetCode 2180. 统计各位数字之和为偶数的整数个数](https://michael.blog.csdn.net/article/details/123145028) |                                                              |
| [LeetCode 2181. 合并零之间的节点（链表）](https://michael.blog.csdn.net/article/details/123145117) |                                                              |
| [LeetCode 2182. 构造限制重复的字符串（贪心、map）](https://michael.blog.csdn.net/article/details/123160764) |                                                              |
| [LeetCode 2185. 统计包含给定前缀的字符串](https://blog.csdn.net/qq_21201267/article/details/123163056) |                                                              |
| [LeetCode 2186. 使两字符串互为字母异位词的最少步骤数](https://blog.csdn.net/qq_21201267/article/details/123163247) |                                                              |
| [LeetCode 2187. 完成旅途的最少时间（二分查找）](https://blog.csdn.net/qq_21201267/article/details/123163469) |                                                              |
| [LeetCode 2190. 数组中紧跟 key 之后出现最频繁的数字](https://michael.blog.csdn.net/article/details/123306036) |                                                              |
| [LeetCode 2191. 将杂乱无章的数字排序（自定义排序）](https://michael.blog.csdn.net/article/details/123307183) |                                                              |
| [LeetCode 2192. 有向无环图中一个节点的所有祖先（拓扑排序）](https://michael.blog.csdn.net/article/details/123308198) |                                                              |
| [LeetCode 2194. Excel 表中某个范围内的单元格](https://michael.blog.csdn.net/article/details/123317776) |                                                              |
| [LeetCode 2195. 向数组中追加 K 个整数（贪心）](https://michael.blog.csdn.net/article/details/123456667) |                                                              |
| [LeetCode 2196. 根据描述创建二叉树（哈希）](https://michael.blog.csdn.net/article/details/123339314) |                                                              |
| [LeetCode 2197. 替换数组中的非互质数（栈）](https://michael.blog.csdn.net/article/details/123455181) |                                                              |
| [LeetCode 2200. 找出数组中的所有 K 近邻下标](https://michael.blog.csdn.net/article/details/123458705) |                                                              |
| [LeetCode 2201. 统计可以提取的工件（哈希）](https://michael.blog.csdn.net/article/details/123459027) |                                                              |
| [LeetCode 2202. K 次操作后最大化顶端元素](https://michael.blog.csdn.net/article/details/123466101) |                                                              |
| [LeetCode 2206. 将数组划分成相等数对](https://michael.blog.csdn.net/article/details/123617407) |                                                              |
| [LeetCode 2207. 字符串中最多数目的子字符串（前缀和）](https://michael.blog.csdn.net/article/details/123618224) |                                                              |
| [LeetCode 2208. 将数组和减半的最少操作次数（优先队列）](https://michael.blog.csdn.net/article/details/123619257) |                                                              |
| [LeetCode 2210. 统计数组中峰和谷的数量](https://michael.blog.csdn.net/article/details/123747098) |                                                              |
| [LeetCode 2211. 统计道路上的碰撞次数](https://michael.blog.csdn.net/article/details/123747485) |                                                              |
| [LeetCode 2212. 射箭比赛中的最大得分（状态枚举）](https://michael.blog.csdn.net/article/details/123763436) |                                                              |
| [LeetCode 2215. 找出两数组的不同（set）](https://blog.csdn.net/qq_21201267/article/details/123773638) |                                                              |
| [LeetCode 2220. 转换数字的最少位翻转次数（位运算）](https://blog.csdn.net/qq_21201267/article/details/123943202) |                                                              |
| [LeetCode 2221. 数组的三角和](https://blog.csdn.net/qq_21201267/article/details/123945641) |                                                              |
| [LeetCode 2222. 选择建筑的方案数](https://blog.csdn.net/qq_21201267/article/details/123945934) |                                                              |
| [LeetCode 2224. 转化时间需要的最少操作数（贪心）](https://blog.csdn.net/qq_21201267/article/details/123946279) |                                                              |
| [LeetCode 2225. 找出输掉零场或一场比赛的玩家（计数）](https://blog.csdn.net/qq_21201267/article/details/123946469) |                                                              |
| [LeetCode 2226. 每个小孩最多能分到多少糖果（二分查找）](https://blog.csdn.net/qq_21201267/article/details/123946676) |                                                              |
| [LeetCode 2231. 按奇偶性交换后的最大数字](https://blog.csdn.net/qq_21201267/article/details/124077249) |                                                              |
| [LeetCode 2232. 向表达式添加括号后的最小结果](https://blog.csdn.net/qq_21201267/article/details/124077622) |                                                              |
| [LeetCode 2233. K 次增加后的最大乘积（优先队列）](https://michael.blog.csdn.net/article/details/124078681) |                                                              |
| [LeetCode 2239. 找到最接近 0 的数字](https://michael.blog.csdn.net/article/details/124225300) |                                                              |
| [LeetCode 2240. 买钢笔和铅笔的方案数](https://michael.blog.csdn.net/article/details/124225496) |                                                              |
| [LeetCode 2241. 设计一个 ATM 机器](https://michael.blog.csdn.net/article/details/124227023) |                                                              |
| [LeetCode 2243. 计算字符串的数字和](https://michael.blog.csdn.net/article/details/124228946) |                                                              |
| [LeetCode 2244. 完成所有任务需要的最少轮数](https://michael.blog.csdn.net/article/details/124229380) |                                                              |
| [LeetCode 2248. 多个数组求交集（set）](https://blog.csdn.net/qq_21201267/article/details/124494209) |                                                              |
| [LeetCode 2249. 统计圆内格点数目](https://blog.csdn.net/qq_21201267/article/details/125826782) |                                                              |
| [LeetCode 2255. 统计是给定字符串前缀的字符串数目](https://blog.csdn.net/qq_21201267/article/details/124522564) |                                                              |
| [LeetCode 2256. 最小平均差（前缀和）](https://blog.csdn.net/qq_21201267/article/details/124523789) |                                                              |
| [LeetCode 2257. 统计网格图中没有被保卫的格子数](https://blog.csdn.net/qq_21201267/article/details/124528094) |                                                              |
| [LeetCode 2259. 移除指定数字得到的最大结果](https://blog.csdn.net/qq_21201267/article/details/124537851) |                                                              |
| [LeetCode 2260. 必须拿起的最小连续卡牌数（哈希）](https://blog.csdn.net/qq_21201267/article/details/124540803) |                                                              |
| [LeetCode 2261. 含最多 K 个可整除元素的子数组](https://blog.csdn.net/qq_21201267/article/details/124541762) |                                                              |
| [LeetCode 2264. 字符串中最大的 3 位相同数字](https://michael.blog.csdn.net/article/details/124646567) |                                                              |
| [LeetCode 2265. 统计值等于子树平均值的节点数(DFS)](https://michael.blog.csdn.net/article/details/124646692) |                                                              |
| [LeetCode 2266. 统计打字方案数（动态规划）](https://michael.blog.csdn.net/article/details/124650352) |                                                              |
| [LeetCode 2267. 检查是否有合法括号字符串路径（BFS）](https://michael.blog.csdn.net/article/details/124649374) |                                                              |
| [LeetCode 2269. 找到一个数字的 K 美丽值](https://blog.csdn.net/qq_21201267/article/details/124778995) |                                                              |
| [LeetCode 2270. 分割数组的方案数（前缀和）](https://blog.csdn.net/qq_21201267/article/details/124779111) |                                                              |
| [LeetCode 2271. 毯子覆盖的最多白色砖块数（前缀和+二分查找）](https://blog.csdn.net/qq_21201267/article/details/124781128) |                                                              |
| [LeetCode 2273. 移除字母异位词后的结果数组](https://blog.csdn.net/qq_21201267/article/details/124781757) |                                                              |
| [LeetCode 2274. 不含特殊楼层的最大连续楼层数](https://blog.csdn.net/qq_21201267/article/details/124781943) |                                                              |
| [LeetCode 2275. 按位与结果大于零的最长组合（位运算）](https://blog.csdn.net/qq_21201267/article/details/124782227) |                                                              |
| [LeetCode 2278. 字母在字符串中的百分比](https://blog.csdn.net/qq_21201267/article/details/124909367) |                                                              |
| [LeetCode 2279. 装满石头的背包的最大数量（贪心）](https://blog.csdn.net/qq_21201267/article/details/124909699) |                                                              |
| [LeetCode 2280. 表示一个折线图的最少线段数（几何）](https://blog.csdn.net/qq_21201267/article/details/124910196) |                                                              |
| [LeetCode 2283. 判断一个数的数字计数是否等于数位的值](https://blog.csdn.net/qq_21201267/article/details/125027670) |                                                              |
| [LeetCode 2284. 最多单词数的发件人](https://blog.csdn.net/qq_21201267/article/details/125027922) |                                                              |
| [LeetCode 2285. 道路的最大总重要性](https://blog.csdn.net/qq_21201267/article/details/125028327) |                                                              |
| [LeetCode 2287. 重排字符形成目标字符串](https://blog.csdn.net/qq_21201267/article/details/125029343) |                                                              |
| [LeetCode 2288. 价格减免](https://blog.csdn.net/qq_21201267/article/details/125029777) |                                                              |
| [LeetCode 2293. 极大极小游戏](https://michael.blog.csdn.net/article/details/125132526) |                                                              |
| [LeetCode 2294. 划分数组使最大差为 K](https://michael.blog.csdn.net/article/details/125132653) |                                                              |
| [LeetCode 2295. 替换数组中的元素](https://michael.blog.csdn.net/article/details/125132909) |                                                              |
| [LeetCode 2296. 设计一个文本编辑器（双栈）](https://michael.blog.csdn.net/article/details/125133217) |                                                              |
| [LeetCode 2299. 强密码检验器 II](https://blog.csdn.net/qq_21201267/article/details/125241564) |                                                              |
| [LeetCode 2300. 咒语和药水的成功对数（二分查找）](https://blog.csdn.net/qq_21201267/article/details/125241605) |                                                              |
| [LeetCode 2301. 替换字符后匹配（字典）](https://blog.csdn.net/qq_21201267/article/details/125241723) |                                                              |
| [LeetCode 2302. 统计得分小于 K 的子数组数目（前缀和+二分查找）](https://blog.csdn.net/qq_21201267/article/details/125244571) |                                                              |
| [LeetCode 2303. 计算应缴税款总额](https://blog.csdn.net/qq_21201267/article/details/125244794) |                                                              |
| [LeetCode 2304. 网格中的最小路径代价（动态规划）](https://blog.csdn.net/qq_21201267/article/details/125245488) |                                                              |
| [LeetCode 2305. 公平分发饼干（DFS）](https://blog.csdn.net/qq_21201267/article/details/125245923) |                                                              |
| [LeetCode 2309. 兼具大小写的最好英文字母](https://blog.csdn.net/qq_21201267/article/details/125357009) |                                                              |
| [LeetCode 2310. 个位数字为 K 的整数之和（枚举）](https://blog.csdn.net/qq_21201267/article/details/125357219) |                                                              |
| [LeetCode 2315. 统计星号（字符串）](https://blog.csdn.net/qq_21201267/article/details/125825695) |                                                              |
| [LeetCode 2319. 判断矩阵是否是一个 X 矩阵](https://blog.csdn.net/qq_21201267/article/details/125825798) |                                                              |
| [LeetCode 2325. 解密消息（map）](https://blog.csdn.net/qq_21201267/article/details/125825948) |                                                              |
| [LeetCode 2331. 计算布尔二叉树的值（树的遍历）](https://blog.csdn.net/qq_21201267/article/details/125826073) |                                                              |
| [LeetCode 2333. 最小差值平方和（贪心）](https://michael.blog.csdn.net/article/details/126070356) |                                                              |
| [LeetCode 2335. 装满杯子需要的最短总时长](https://blog.csdn.net/qq_21201267/article/details/125826157) |                                                              |
| [LeetCode 2336. 无限集中的最小数字（SortedSet）](https://michael.blog.csdn.net/article/details/126069612) |                                                              |
| [LeetCode 2341. 数组能形成多少数对](https://michael.blog.csdn.net/article/details/126006700) |                                                              |
| [LeetCode 2342. 数位和相等数对的最大和](https://michael.blog.csdn.net/article/details/126065592) |                                                              |
| [LeetCode 2343. 裁剪数字后查询第 K 小的数字](https://michael.blog.csdn.net/article/details/126071169) |                                                              |
| [LeetCode 2347. 最好的扑克手牌](https://michael.blog.csdn.net/article/details/126006724) |                                                              |
| [LeetCode 2348. 全 0 子数组的数目](https://michael.blog.csdn.net/article/details/126065763) |                                                              |
| [LeetCode 2349. 设计数字容器系统（SortedSet）](https://michael.blog.csdn.net/article/details/126070776) |                                                              |
| [LeetCode 2351. 第一个出现两次的字母](https://michael.blog.csdn.net/article/details/126006736) |                                                              |
| [LeetCode 2352. 相等行列对](https://michael.blog.csdn.net/article/details/126065925) |                                                              |
| [LeetCode 2353. 设计食物评分系统（sortedcontainers）](https://michael.blog.csdn.net/article/details/126069358) |                                                              |
| [LeetCode LCP 11. 期望个数统计](https://michael.blog.csdn.net/article/details/105755974) |                                                              |
| [LeetCode LCP 12. 小张刷题计划（二分查找）](https://michael.blog.csdn.net/article/details/105921940) |                                                              |
| [LeetCode LCP 17. 速算机器人](https://michael.blog.csdn.net/article/details/108553304#1_LeetCode_LCP_17__easy_18) |                                                              |
| [LeetCode LCP 18. 早餐组合（排序+二分）](https://michael.blog.csdn.net/article/details/108553304#2_LeetCode_LCP_18__easy_70) |                                                              |
| [LeetCode LCP 19. 秋叶收藏集（DP）](https://michael.blog.csdn.net/article/details/108553304#3_LeetCode_LCP_19__medium_189) |                                                              |
| [LeetCode LCP 22. 黑白方格画](https://michael.blog.csdn.net/article/details/108684240) |                                                              |
| [LeetCode LCP 28. 采购方案（排序 + 二分查找）](https://blog.csdn.net/qq_21201267/article/details/115446534) |                                                              |
| [LeetCode LCP 29. 乐团站位（数学 等差数列）](https://blog.csdn.net/qq_21201267/article/details/115447506) |                                                              |
| [LeetCode LCP 30. 魔塔游戏（优先队列）](https://blog.csdn.net/qq_21201267/article/details/115446727) |                                                              |
| [LeetCode LCP 33. 蓄水（暴力枚举）](https://michael.blog.csdn.net/article/details/115581556) |                                                              |
| [LeetCode LCP 34. 二叉树染色（树上DP）](https://michael.blog.csdn.net/article/details/115582515) |                                                              |
| [LeetCode LCP 50. 宝石补给](https://michael.blog.csdn.net/article/details/124219727) |                                                              |
| [LeetCode LCP 51. 烹饪料理（状态枚举）](https://michael.blog.csdn.net/article/details/124220061) |                                                              |
| [LeetCode LCP 55. 采集果实](https://blog.csdn.net/qq_21201267/article/details/124369785) |                                                              |
| [LeetCode LCP 56. 信物传送（迪杰斯特拉-最短路径）](https://blog.csdn.net/qq_21201267/article/details/124369898) |                                                              |
| [LeetCode 网易-1. 分割环（前缀和 + 哈希）](https://michael.blog.csdn.net/article/details/109208128) |                                                              |
| [LeetCode 网易-2. 古老的游戏机](https://michael.blog.csdn.net/article/details/109207550) |                                                              |
| [LeetCode meituan-001. 小美的用户名](https://michael.blog.csdn.net/article/details/119720078) |                                                              |
| [LeetCode meituan-003. 小美的跑腿代购（排序）](https://michael.blog.csdn.net/article/details/119747085) |                                                              |
| [LeetCode meituan-006. 小团的神秘暗号](https://michael.blog.csdn.net/article/details/119747176) |                                                              |
| [LeetCode meituan-007. 小团的选调计划（模拟）](https://michael.blog.csdn.net/article/details/119793259) |                                                              |
| [LeetCode DD-2020006. 简单游戏（前缀和）](https://michael.blog.csdn.net/article/details/112688247) |                                                              |
| [LeetCode LCS 01. 下载插件](https://michael.blog.csdn.net/article/details/118055279) |                                                              |
| [LeetCode LCS 02. 完成一半题目（计数+排序）](https://michael.blog.csdn.net/article/details/118055667) |                                                              |
| [LeetCode LCS 03. 主题空间（广度优先搜索BFS）](https://michael.blog.csdn.net/article/details/118056312) |                                                              |





---

我的CSDN[博客地址 https://michael.blog.csdn.net/](https://michael.blog.csdn.net/)

长按或扫码关注我的公众号（Michael阿明），一起加油、一起学习进步！
![Michael阿明](https://img-blog.csdnimg.cn/20200630084921292.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzIxMjAxMjY3,size_16,color_FFFFFF,t_70)