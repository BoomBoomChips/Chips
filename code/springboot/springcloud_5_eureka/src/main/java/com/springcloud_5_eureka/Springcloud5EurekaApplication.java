package com.springcloud_5_eureka;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.netflix.eureka.server.EnableEurekaServer;

@SpringBootApplication
@EnableEurekaServer
public class Springcloud5EurekaApplication {

    public static void main(String[] args) {
        SpringApplication.run(Springcloud5EurekaApplication.class, args);
    }

}
