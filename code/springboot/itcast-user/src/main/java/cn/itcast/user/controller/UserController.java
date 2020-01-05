package cn.itcast.user.controller;

import cn.itcast.user.pojo.User;
import cn.itcast.user.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Controller
@RequestMapping("user")
public class UserController {

    @Autowired
    private UserService userService;

    @GetMapping("{id}")
    @ResponseBody
    public User queryUserById(@PathVariable("id")Long id){
        return this.userService.queryUserById(id);
    }

    @GetMapping("all/list")
    public String toUsers(Model model){

        List<User> users = this.userService.queryUserAll();
        model.addAttribute("users", users);
        return "users";
    }


    @GetMapping("test")
    @ResponseBody
    public String test(){
        return "hello user!";
    }

}
