package com.videostudy.springboot_2_user;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import tk.mybatis.spring.annotation.MapperScan;

@SpringBootApplication
/**
 * 不知道为啥用了mapperscan和mapper有啥区别
 */
@MapperScan("com.videostudy.springboot_2_user.mapper")
public class Springboot2UserApplication {

    public static void main(String[] args) {
        SpringApplication.run(Springboot2UserApplication.class, args);
    }

}
