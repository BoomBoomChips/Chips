package com.springcloud_3_provider;


import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import tk.mybatis.spring.annotation.MapperScan;

@SpringBootApplication
@MapperScan("com.springcloud_3_provider.mapper")
@EnableDiscoveryClient
public class Springcloud3ProviderApplication {

    public static void main(String[] args) {
        SpringApplication.run(Springcloud3ProviderApplication.class, args);
    }

}
