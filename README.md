# code
This project is developed using Tuya SDK, which enables you to quickly develop branded apps connecting and controlling smart scenarios of many devices. For more information, please check Tuya Developer Website

  此次为基于涂鸦模块的智能家居监测仪的项目，详细内容请前往立创开源平台 https://oshwhub.com/leichaolin/zhi-neng-ju-jia-jian-kong-yi
  如对项目有任何疑问请联系作者 雷超林 湖南职业技术学院5524研究所

This is a project of smart home monitor based on graffiti module. Please go to Lichuang open source platform for details https://oshwhub.com/leichaolin/zhi-neng-ju-jia-jian-kong-yi
If you have any questions about the project, please contact Lei Chaolin, 5524 Research Institute of Hunan Vocational and technical college

  涂鸦WB3S物联网模块有两种模式；第一就是免开发，通俗易懂点，就是不用自己写代码，拿到手就能用。
我一直在思考为什么不用写代码呢，原来在lot平台配置的时候已经把需要的功能提交了，发货时就是已经烧录好固件的。第二个模式就是低代码MUC开发：通过移植SDK来控制物联网模块完成一些高级操作，虽然说是低代码，对于我这种小白来说，还是有难度的（低调），本身涂鸦物联网是通过特定的协议和MCU通信，来获得当前的环境温度、湿度等信息，再上传到云端，手机上就可以查看了。关于涂鸦物联网模块我就介绍到这里，其他更多信息，请观看立创哔哩哔哩视频 https://www.bilibili.com/video/BV1S54y167v1
涂鸦智能官网 https://www.tuya.com/cn/

  Graffiti wb3s Internet of things module has two modes; the first is free development, easy to understand, that is, you don't need to write your own code, you can use it when you get it.
  I've been thinking about why I don't need to write code. Originally, the required functions were submitted when the lot platform was configured, and the firmware was burned when it was delivered. The second mode is low code MUC development: transplant the SDK to control the IOT module to complete some advanced operations. Although it's low code, it's still difficult (low-key) for me. The graffiti IOT itself communicates with MCU through a specific protocol to obtain the current environmental temperature, humidity and other information, which can be uploaded to the cloud and checked on the mobile phone Yes. I will introduce the graffiti Internet of things module here. For more information, please watch Lichuang Bili Bili video https://www.bilibili.com/video/BV1S54y167v1
  Graffiti smart official website https://www.tuya.com/cn/

  下载SDK文件，将文件编译到我们mian函数中，具体操作查看涂鸦官网操作，
网址：https://developer.tuya.com/cn/docs/iot/device-development/embedded-software-development/module-sdk-development-access/module-sdk-development-guide?id=K9tjznxb6vf2x
哔哩哔哩官网视频：https://www.bilibili.com/video/BV1pb41117Nt
  关于移植SDK，我们只需要将我们用到的功能一一对应起来即可，通过串口自动会将信息上传给涂鸦WB3S，物联网模块则将数据上发到我们云端。实现我们产品每一个功能。
代码我将上传到附件中

Download the SDK file, compile the file into our Mian function, and check the graffiti official website for details,
website: https://developer.tuya.com/cn/docs/iot/device-development/embedded-software-development/module-sdk-development-access/module-sdk-development-guide?id=K9tjznxb6vf2x
BiliBili official website video: https://www.bilibili.com/video/BV1pb41117Nt
As for the transplantation of SDK, we only need to match the functions we use one by one. Through the serial port, we will automatically upload the information to the graffiti wb3s, and the Internet of things module will send the data to our cloud. Realize every function of our products.
I will upload the code to the attachment
