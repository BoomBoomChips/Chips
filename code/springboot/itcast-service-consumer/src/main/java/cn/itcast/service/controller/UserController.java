package cn.itcast.service.controller;

import cn.itcast.service.client.UserClient;
import cn.itcast.service.pojo.User;
import com.netflix.hystrix.contrib.javanica.annotation.DefaultProperties;
import com.netflix.hystrix.contrib.javanica.annotation.HystrixCommand;
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
//@DefaultProperties(defaultFallback = "fallbackMethod") // 定义全局的熔断方法
public class UserController {

    @Autowired
    private UserClient userClient;

    //@Autowired
    //private RestTemplate restTemplate;

//    @Autowired
//    private DiscoveryClient discoveryClient; // 包含了拉取的所有服务信息

    @GetMapping
    @ResponseBody
    @HystrixCommand // 声明熔断的方法
    public String queryUserById(@RequestParam("id")Long id){
        /*if (id == 1) {
            throw new RuntimeException();
        }*/
        /*List<ServiceInstance> instances = discoveryClient.getInstances("service-provider");
        ServiceInstance instance = instances.get(0);*/
        //return this.restTemplate.getForObject("http://service-provider/user/" + id, String.class);
        return this.userClient.queryUserById(id).toString();
    }

    /*public String fallbackMethod(){
        return "服务正忙，请稍后再试！";
    }*/
}
