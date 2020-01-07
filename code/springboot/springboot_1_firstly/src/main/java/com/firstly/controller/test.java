package com.firstly.controller;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@ComponentScan
@RequestMapping("user")
public class test {

    @ResponseBody
    @RequestMapping("abc")
    public String testfanhui(){
        return "hello everyone !";
    }
}
