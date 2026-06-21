# 4-axis-robotic-arm-MeArm
四轴机械臂的复现，简单记录一下学习过程

在b站上看到了一个视频https://www.bilibili.com/video/BV1tr4y1e7E2/?spm_id_from=333.1007.top_right_bar_window_custom_collection.content.click&vd_source=44c951660591e5e7df45c28003acbf96

感觉蛮有意思的，正好最近在学Arduino，就自己在淘宝上买了MeArm的开源机械臂，想复刻一个玩玩

对Arduino的学习主要是看b站上的教学视频

https://www.bilibili.com/video/BV164411J7GE?spm_id_from=333.788.recommend_more_video.1&trackid=web_related_0.router-related-2589621-z4htq.1779593635388.1018&vd_source=44c951660591e5e7df45c28003acbf96

https://www.bilibili.com/video/BV1k4411J7XD?spm_id_from=333.788.videopod.episodes&vd_source=44c951660591e5e7df45c28003acbf96&p=9


下面是组装好了之后的机械臂
<img width="1280" height="960" alt="b6dc65109ee590fe73685b0af35e3ff4_720" src="https://github.com/user-attachments/assets/09a2d10f-00bf-441c-b3db-af3137ca0822" />
网上买的MeArm机械臂是亚克力材质的，很脆，中间固定舵机的时候，有块板断了三次，最后拿502和牙签给固定住了，哈哈

<img width="1280" height="960" alt="1d029d4bed1f8193794529d58967d352_720" src="https://github.com/user-attachments/assets/e68d5902-2b43-46f6-a4b0-7c5680f89f89" />

<img width="1280" height="960" alt="fac3e04fa42eb552d83e23d99fb49886_720" src="https://github.com/user-attachments/assets/b31a1d7f-2a8c-467c-b477-2b6f68bb42b8" />

下面是接好线之后的机械臂
<img width="1280" height="960" alt="46c8f0fafe07867bc7e861a0ce25bafd_720" src="https://github.com/user-attachments/assets/39167bd4-7b12-491b-aeca-04ce9eba756f" />

具体的接线图：

<img width="840" height="576" alt="c7cd04c1264b44e30928b94d09a84a53" src="https://github.com/user-attachments/assets/3a21a5b2-3550-4f6d-a0f6-3ad5fa0a96aa" />

给面包板和开发板接上电源，开发板还要链接数据线用来烧录程序：
<img width="1280" height="960" alt="9009ffff4664387fd0eda56123b9bf9d_720" src="https://github.com/user-attachments/assets/3fb0e53c-2c71-43d4-b632-57d466c1ece2" />

舵机初始化使用MeArm_Init.ino在机械臂组装之前对舵机进行初始化，组装完成后再使用MeArm.ino进行测试


在Arduino IDE上烧录程序后，在Serial Monitor中输入o就可以看到每个舵机初始设置的角度


在Serial Monitor中还可以指定舵机旋转到特定的角度

<img width="1678" height="325" alt="b044a64401810db6e4b0ab7efd48f404" src="https://github.com/user-attachments/assets/e7daccb4-7548-4504-9122-efee87120172" />

<img width="1686" height="331" alt="3b4e8e0e0b79270a9b6d805d21e8c88a" src="https://github.com/user-attachments/assets/8cde1ed8-c8ee-4389-b9e2-f3b7892e79cc" />



