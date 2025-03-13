// Startup.cs

public void ConfigureServices(IServiceCollection services)
{
    services.AddDbContext<ApplicationDbContext>(options =>
        options.UseInMemoryDatabase("InMemoryDatabase")); // Use in-memory database
    services.AddControllersWithViews();
}

// HomeController.cs

[Authorize]
public class HomeController : Controller
{
    private readonly ApplicationDbContext _context;

    public HomeController(ApplicationDbContext context)
    {
        _context = context;
    }

    public IActionResult Index()
    {
        var contact = _context.Contacts.Find(User.Identity.Name); // Fix: Use correct ID type
        return View(contact);
    }

    [HttpPost]
    public IActionResult Index(Contact contact)
    {
        if (ModelState.IsValid)
        {
            var existingContact = _context.Contacts.FirstOrDefault(c => c.Id == contact.Id); // Fix: Find the contact by ID
            if (existingContact != null)
            {
                existingContact.Name = contact.Name;
                existingContact.Email = contact.Email;
                existingContact.Message = contact.Message;
                _context.Contacts.Update(existingContact);
            }
            else
            {
                _context.Contacts.Add(contact); // Fix: AddOrUpdate replaced with Add
            }
            
            _context.SaveChanges();
            return RedirectToAction("Index");
        }
        return View(contact);
    }
}

// Models/Contact.cs

public class Contact
{
    public int Id { get; set; }
    public string Name { get; set; }
    public string Email { get; set; }
    public string Message { get; set; }
}

// ApplicationDbContext.cs

public class ApplicationDbContext : DbContext
{
    public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
        : base(options)
    {
    }

    public DbSet<Contact> Contacts { get; set; }
}
