# Computer-room-reservation-system

## 1 机房预约系统简介

#### 1.1 开发需求
学校有几个规格不同的机房， 由于使用时经常出现“撞车”现象，现开发一套机房预约系统，解决这一问题。

#### 1.2 身份简介
分别有三种身份使用该系统：
- 学生代表： 申请使用机房
- 教师： 审核学生的预约申请
- 管理员： 给学生、教师创建账号

#### 1.3 机房简介
机房总共有三个：
- 1号机房 — 最大容量20人
- 2号机房 — 最大容量50人
- 3号机房 — 最大容量100人

#### 1.4 申请简介
- 申请的订单每周由管理员负责清空
- 学生可以预约未来一周内的机房使用，预约的日期为周一至周五，预约时需要选择预约时段(上午、下午)
- 教师来审核预约，依赖实际情况审核预约通过或者不通过

## 2 功能设计

#### 2.1 系统具体需求
首先进入登录界面，可选登录身份有：
- 学生代表
- 老师
- 管理员
- 退出

每个身份都需要进行登录验证，分别进入子菜单：
- 学生需要输入：学号、姓名、登录密码
- 老师需要输入：职工号、姓名、登陆密码
- 管理员需要输入：管理员姓名、登录密码

#### 2.2 学生具体功能
- 申请预约 — 预约机房
- 查看自身的预约 — 查看自己的预约状态
- 查看所有预约 — 查看全部预约信息以及预约状态
- 取消预约 — 取消自身的预约，预约成功或审核中的预约均可以取消
- 注销登录 — 退出登录

#### 2.3 教师具体功能
- 查看所有预约 — 查看全部预约信息以及预约状态
- 审核预约 — 对学生的预约进行审核
- 注销登录 — 退出登录

#### 2.4 管理员具体功能
- 添加账号 — 添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
- 查看账号 — 可以选择查看学生或教师的全部信息
- 查看机房 — 查看所有机房的信息
