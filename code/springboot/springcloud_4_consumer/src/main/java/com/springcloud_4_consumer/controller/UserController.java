package com.springcloud_4_consumer.controller;


import com.netflix.hystrix.contrib.javanica.annotation.HystrixCommand;
import com.springcloud_4_consumer.client.UserClient;
import com.springcloud_4_consumer.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.discovery.DiscoveryClient;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.client.RestTemplate;

import java.util.List;

@Controller
@RequestMapping("consumer/user")
//@DefaultProperties(defaultFallback = "fallbackMethod") // 定义全局的熔断方法,因为不是每个方法都是要熔断的
public class UserController {

    @Autowired
    private UserClient userClient;

//    @Autowired
//    private RestTemplate restTemplate;

//    @Autowired
//    private DiscoveryClient discoveryClient; // 包含了拉取的所有服务信息

//    @GetMapping
//    @ResponseBody
//    @HystrixCommand(fallbackMethod = "queryUserByIdfallback") // 声明熔断的方法
    public String queryUserById(@RequestParam("id")Long id){

        return userClient.queryUserById(id).toString();

        /*if (id == 1) {
            throw new RuntimeException();
        }*/
//        List<ServiceInstance> instances = discoveryClient.getInstances("service-provider");
//        ServiceInstance instance = instances.get(0);
//        return this.restTemplate.getForObject("http://"+instance.getHost()+":"+instance.getPort()+"/user/" + id, User.class);
//        return this.restTemplate.getForObject("http://server-provider/user/" + id, String.class);
//        return this.userClient.queryUserById(id).toString();
    }
//
////    注意，熔断和你要被熔断的方法保持一致，为了测试就算了
//    public String queryUserByIdfallback(){
//        return "服务正忙，请稍后再试！";
//    }
}
