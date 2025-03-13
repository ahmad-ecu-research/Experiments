using Microsoft.AspNetCore.Mvc;
using YourNamespace.Models;

public class HomeController : Controller
{
    private static Contact _contact = new Contact();

    public IActionResult Index()
    {
        return View(_contact);
    }

    [HttpPost]
    public IActionResult Index(Contact contact)
    {
        if (ModelState.IsValid)
        {
            _contact = contact;
            return RedirectToAction("Index");
        }
        return View(contact);
    }
}
